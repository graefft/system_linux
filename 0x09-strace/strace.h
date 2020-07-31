#ifndef __STRACE_H__
#define __STRACE_H__

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/reg.h>
#include <sys/user.h>
#include <sys/wait.h>

char *read_string(pid_t child, unsigned long address);
int trace_me(char **argv, char **env);
unsigned long get_syscall_arg(struct user_regs_struct reg, int index);
int wait_for_syscall(pid_t child_pid);

#endif /*__STRACE_H__*/
