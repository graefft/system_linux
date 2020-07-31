#include "strace.h"
#include "syscalls.h"

/**
 * print_syscall - prints syscall arguments
 *
 * @reg: struct with register information
 * @argc: number of command line arguments
 * @argv: command line arguments
 * @env: environment variables
 * @pid: pid of tracee
 * @reg: register struct
 */
void print_syscall(int argc, char **argv, char **env, pid_t pid, struct
		user_regs_struct reg)
{
	int num_args = 0, i = 0;
	unsigned long arg;

	ptrace(PTRACE_GETREGS, pid, 0, &reg);
	if (strcmp(syscalls_64_g[(size_t) reg.orig_rax].name, "execve") == 0)
	{
		printf("execve(\"%s\", [", argv[1]);
		for (i = 1; i < argc; ++i)
		{
			printf("\"%s\"", argv[i]);
			if (i < argc - 1)
				printf(", ");
		}
		for (i = 0; env[i]; i++)
			;
		printf("], [/* %d vars */]) = 0\n", i);
	}
	else
	{
		num_args = syscalls_64_g[(size_t)reg.orig_rax].nb_params;
		for (i = 0; i < num_args; i++)
		{
			arg = get_syscall_arg(reg, i);
			if (syscalls_64_g[(size_t)reg.orig_rax].params[i] == VARARGS)
				printf("...");
			else if (syscalls_64_g[(size_t)reg.orig_rax].params[i] == CHAR_P)
				printf("\"%s\"", read_string(pid, arg));
			else
				printf("%#lx", arg);
			if (i < num_args - 1)
				printf(", ");
		}
	}
}

/**
 * run_tracer - runs tracer from parent
 *
 * @pid: pid of child to be traced
 * @argc: number of arguments
 * @argv: command line arguments
 * @env: environment variables
 * Return: 0 on success
 */
int run_tracer(pid_t pid, int argc, char *argv[], char **env)
{
	int status;
	struct user_regs_struct reg;

	waitpid(pid, &status, 0);
	ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_TRACESYSGOOD);

	while (1)
	{
		if (wait_for_syscall(pid) != 0)
			break;
		ptrace(PTRACE_GETREGS, pid, 0, &reg);

		printf("%s(", syscalls_64_g[reg.orig_rax].name);
		print_syscall(argc, argv, env, pid, reg);
		fflush(stdout);
		if (wait_for_syscall(pid))
			break;
		ptrace(PTRACE_GETREGS, pid, 0, &reg);
		printf(") = %lx\n", (unsigned long)reg.rax);
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
		trace_me(argv + 1, env);
	else if (pid > 0)
		run_tracer(pid, argc, argv, env);
	else
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	return (0);
}
