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
 * handle_signal - Function that sets a handler for the signal SIGINT
 * Return: 0 on success, -1 on error
 */
int handle_signal(void)
{
	if (signal(SIGINT, my_handler) != SIG_ERR)
		return (0);
	else
		return (-1);
}
