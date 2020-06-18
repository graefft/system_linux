#include "strace.h"
#include "syscalls.h"

/**
 * trace_me - traces child
 * @argv: arguments
 * @env: environment
 * Return: 0 or -1
 */
int trace_me(char **argv, char **env)
{
	ptrace(PTRACE_TRACEME, 0, 0, 0);
	kill(getpid(), SIGSTOP);
	execve(argv[0], argv, env);
	return (0);
}

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
			printf("%#lx", get_syscall_arg(reg, i));
			if (i < num_args - 1)
				printf(", ");
		}

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
 * get_syscall_arg - retrieves register for arguments of command
 * @reg: register struct
 * @index: index of argument
 * Return: register value
 */
unsigned long get_syscall_arg(struct user_regs_struct reg, int index)
{
	switch (index)
	{
		case 0: return (reg.rdi);
		case 1: return (reg.rsi);
		case 2: return (reg.rdx);
		case 3: return (reg.r10);
		case 4: return (reg.r8);
		case 5: return (reg.r9);
	}
	return (0);
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
