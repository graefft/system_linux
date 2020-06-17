#ifndef __STRACE_H__
#define __STRACE_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>

int trace_child(char**argv, char **env);
int trace_from_parent(pid_t child_pid);
int wait_for_syscall(pid_t child_pid);

#endif /*__STRACE_H__*/
