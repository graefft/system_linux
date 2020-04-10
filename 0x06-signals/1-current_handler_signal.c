#include "signals.h"

/**
 * current_handler_signal - retrieves current handler of the signal SIGINT
 * Return: void
 */
void (*current_handler_signal(void))(int)
{
	void (*handler)(int);

	handler = signal(SIGINT, SIG_DFL);

	if (signal(SIGINT, handler) == SIG_ERR)
		return (NULL);
	else
		return (handler);
}
