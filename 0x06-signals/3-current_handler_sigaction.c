#include "signals.h"

/**
 * current_handler_sigaction - retrieves current handler of the signal SIGINT
 * Return: void
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction query_action;

	if (sigaction(SIGINT, &query_action, NULL) == -1)
		return (NULL);
	else
		return (query_action.sa_handler);
}
