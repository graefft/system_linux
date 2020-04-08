#ifndef __SIGNALS_H__
#define __SIGNALS_H__

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int handle_signal(void);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);
int pid_exist(pid_t pid);

#endif /* __SIGNALS_H__ */
