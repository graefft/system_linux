#include "strace.h"
#include "syscalls.h"

/**
 * tracee - traces child
 * @argv: arguments
 * @env: environment
 * Return: 0 or -1
 */
int tracee(char **argv, char **env)
{
	ptrace(PTRACE_TRACEME, 0, 0, 0);
	kill(getpid(), SIGSTOP);
	execve(argv[0], argv, env);
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
	struct user_regs_struct reg;

	waitpid(pid, &status, 0);
	ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_TRACESYSGOOD);
	while (1)
	{
		if (wait_for_syscall(pid))
			break;
		ptrace(PTRACE_GETREGS, pid, 0, &reg);
		printf("%s", syscalls_64_g[(size_t) reg.orig_rax].name);
		fflush(stdout);
		if (wait_for_syscall(pid))
			break;
		putchar('\n');
	}
	putchar('\n');
	return (1);
}

/**
 * wait_for_syscall - waits for syscall
 * @pid: child pid
 * Return: 0 if syscall
 */
int wait_for_syscall(pid_t pid)
{
	int status;

	while (1)
	{
		ptrace(PTRACE_SYSCALL, pid, 0, 0);
		waitpid(pid, &status, 0);
		if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80)
			return (0);
		if WIFEXITED(status)
			return (1);
	}
	return (1);
}

/**
 * main - executes and traces a given command
 * @argc: number of arguments
 * @argv: command to trace
 * @env: environment
 * Return: 0 on success, -1 on failures
 */
int main(int argc, char **argv, char **env)
{
	pid_t pid;

	if (argc < 2)
	{
		printf("Usage: command\n");
		return (EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
	{
		tracee(argv + 1, env);
	}
	else if (pid > 0)
	{
		tracer(pid);
	}
	else
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	return (0);
}
