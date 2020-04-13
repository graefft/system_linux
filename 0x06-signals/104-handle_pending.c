#include "signals.h"

/**
 * handle_pending - handler for all pending signals of current pid
 * @handler: handler to set
 * Return: 0 on success, -1 on error
 */
int handle_pending(void (*handler)(int))
{
	struct sigaction pending_action;
	sigset_t pending_signals;
	int i;

	pending_action.sa_handler = handler;

	if (sigpending(&pending_signals) < 0)
		return (-1);

	for (i = 1; i <= SIGRTMAX; i++)
	{
		if (sigismember(&pending_signals, i))
		{
			if (sigaction(i, &pending_action, NULL) < 0)
				return (-1);
		}
	}
	return (0);
}
