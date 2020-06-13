#include "strace.h"
#include "syscalls.h"

/**
 * tracee - traces child
 * @argv: arguments
 * Return: 0 or -1
 */
int tracee(char **argv)
{
	ptrace(PTRACE_TRACEME, 0, 0, 0);
	kill(getpid(), SIGSTOP);
	execve(argv[0], argv, NULL);
	return (0);
}

/**
 * tracer - runs tracer from parent
 * @pid: pid of child to be traced
 * Return: 0 on success
 */
int tracer(pid_t pid)
{
	int status;

	waitpid(pid, &status, 0);
	ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_0_TRACESYSGOOD);
	while (WIFEXITED(status))
	{
		ptrace(PTRACE_SYSCALL, pid, 0, 0);
		waitpid(pid, &status, 0);
		if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80)
			return (0);
	}
	return (1);
}

/**
 * main - executes and traces a given command
 * @argc: number of arguments
 * @argv: command to trace
 * Return: 0 on success, -1 on failures
 */
int main(int argc, char **argv)
{
	pid_t pid;

	if (argc != 2)
	{
		printf("Usage: command\n");
		return (EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
		tracee(argv + 1);
	else if (pid > 0)
		tracer(pid);
	else
	{
		perror("Fork failed");
		exit(0);
	}
	return (0);
}
