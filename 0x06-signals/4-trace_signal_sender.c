#include "signals.h"

/**
 * trace_handler - handler for SIGQUIT to demonstrate obtaining pid
 * @sig: SIGNUM
 * @siginfo: info struct for SIG to access si_pid
 * @context: not used
 * Return: void
 */
void trace_handler(int sig, siginfo_t *siginfo, void *context)
{
	pid_t sender_pid = siginfo->si_pid;
	(void)sig;
	(void)context;

	printf("SIGQUIT sent by %d\n", sender_pid);
}


/**
 * trace_signal_sender - defines a handler for the signal SIGQUIT
 * Return: 0 on success, -1 on failure
 */
int trace_signal_sender(void)
{
	struct sigaction act;

	printf("process [%d] started.\n", (int)getpid());

	act.sa_sigaction = trace_handler;
	act.sa_flags = SA_SIGINFO;

	if (sigaction(SIGQUIT, &act, NULL) != 0)
	{
		printf("ERROR ACTION\n");
		return (-1);
	}
	return (0);
}
