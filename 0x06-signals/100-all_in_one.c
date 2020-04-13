#include "signals.h"

/**
 * all_in_one_handler - handler for all_in_one function
 * @sig: SIGNUM
 * @siginfo: info struct for SIG to print info
 * @context: not used
 * Return: void
 */
void all_in_one_handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)sig;
	(void)context;
	psiginfo(siginfo, "Caught");
}

/**
 * all_in_one - sets up a single handler for all signals
 */
void all_in_one(void)
{
	int i;
	struct sigaction act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = all_in_one_handler;

	for (i = 0; i <= SIGRTMAX; i++)
		sigaction(i, &act, NULL);
}
