#include "signals.h"

/**
 * my_handler - Sets handler for signal 'sig'
 * @sig: number of signal sent
 * Return: void
 */
void my_handler(int sig)
{
	printf("Gotcha! [%d]\n", sig);
	fflush(stdout);
}

/**
 * handle_sigaction - Function that sets a handler for the signal SIGINT
 * Return: 0 on success, -1 on error
 */
int handle_sigaction(void)
{
	struct sigaction new_action;

	new_action.sa_handler = my_handler;
	return (sigaction(SIGINT, &new_action, NULL));
}
