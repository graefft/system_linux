#ifndef __SIGNALS_H__
#define __SIGNALS_H__

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

int handle_signal(void);
void my_handler(int sig);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
void suspend_handler(int sig);
int trace_signal_sender(void);
void trace_handler(int sig, siginfo_t *siginfo, void *context);
int pid_exist(pid_t pid);
void all_in_one(void);
int sigset_init(sigset_t *set, int *signals);
int signals_block(int *signals);
int signals_unblock(int *signals);
int handle_pending(void (*handler)(int));
void all_in_one_handler(int sig, siginfo_t *siginfo, void *context);
void sigset_print(const sigset_t *set);
int signals_block(int *signals);
int signals_unblock(int *signals);
int handle_pending(void (*handler)(int));
void handler(int signum);

#endif /* __SIGNALS_H__ */
