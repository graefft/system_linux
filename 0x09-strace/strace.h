#ifndef __STRACE_H__
#define __STRACE_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>

int tracee(char**argv, char **env);
int tracer(pid_t child_pid);
int wait_for_syscall(pid_t child_pid);

#endif /*__STRACE_H__*/
