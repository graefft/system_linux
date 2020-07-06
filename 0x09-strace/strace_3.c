#include "strace.h"
#include "syscalls.h"

/**
 * run_tracer - runs tracer from parent
 * @pid: pid of child to be traced
 * Return: 0 on success
 */
int run_tracer(pid_t pid)
{
	const char *syscall;
	int i, status, num_args = 0;
	struct user_regs_struct reg;
	unsigned long arg;

	waitpid(pid, &status, 0);
	ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_TRACESYSGOOD);
	while (1)
	{
		if (wait_for_syscall(pid))
			break;
		/* print syscall name */
		ptrace(PTRACE_GETREGS, pid, 0, &reg);
		syscall = (syscalls_64_g[(size_t)reg.orig_rax].name);
		printf("%s(", syscall);

		/* print syscall args */
		num_args = syscalls_64_g[(size_t)reg.orig_rax].nb_params;
		for (i = 0; i < num_args; i++)
		{
			arg = get_syscall_arg(reg, i);
			if (syscalls_64_g[(size_t)reg.orig_rax].params[i] == VARARGS)
				printf("...");
			else if (syscalls_64_g[(size_t)reg.orig_rax].params[i] != VOID)
				printf("%#lx", arg);
			if (i < num_args - 1)
				printf(", ");
		}
		fflush(stdout);
		if (wait_for_syscall(pid))
			break;
		/* print return value of syscall */
		ptrace(PTRACE_GETREGS, pid, 0, &reg);
		printf(") = %#lx\n", (unsigned long)reg.rax);
		fflush(stdout);
	}
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
		{
			printf(") = ?\n");
			return (1);
		}
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
		trace_me(argv + 1, env);
	}
	else if (pid > 0)
	{
		run_tracer(pid);
	}
	else
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	return (0);
}
