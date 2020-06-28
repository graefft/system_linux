#include "strace.h"

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
 * read_string - reads a NULL-terminated string from child
 * @child: child to read from
 * @address: address of string to read
 * Return: string
 */
char *read_string(pid_t child, unsigned long address)
{
	char *value = malloc(4096);		/* buffer to copy string into */
	unsigned int allocated = 4096;	/* how much data has been allocated */
	unsigned int read = 0;			/* how much data has been copied */
	unsigned long tmp = 0;			/* temp variable for reading memory */

	while (1)
	{
		/* grow buffer if necessary */
		if (read + sizeof(tmp) > allocated)
		{
			allocated *= 2;
			value = realloc(value, allocated);
		}
		/* read data one word at a time */
		tmp = ptrace(PTRACE_PEEKDATA, child, address + read);
		if (errno != 0)
		{
			value[read] = 0;
			break;
		}
		/* append data read */
		memcpy(value + read, &tmp, sizeof(tmp));
		/* found terminating NULL */
		if (memchr(&tmp, 0, sizeof(tmp)) != NULL)
			break;
		read += sizeof(tmp);
	}
	return (value);
}
