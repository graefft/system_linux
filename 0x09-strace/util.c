#include "strace.h"

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

