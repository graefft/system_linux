#include "signals.h"

/**
 * suspend_handler - Sets handler and prints for signal 'sig'
 *
 * ***printf used for educational purposes only***
 *
 * @sig: number of signal sent
 * Return: void
 */
void suspend_handler(int sig)
{
	printf("Caught %d\n", sig);
	printf("Signal received\n");
	fflush(stdout);
	exit(EXIT_SUCCESS);
}

/**
 * handle_signal - Function that sets a handler for the signal SIGINT
 * Return: 0 on success, -1 on error
 */
int handle_signal(void)
{
	if (signal(SIGINT, suspend_handler) != SIG_ERR)
		return (0);
	else
		return (-1);
}

/**
 * main - Function that sets a handler for the signal SIGINT
 * Return: 0 on success, -1 on error
 */
int main(void)
{
	if (handle_signal() != 0)
		return (EXIT_FAILURE);

	pause();
	return (EXIT_SUCCESS);
}
