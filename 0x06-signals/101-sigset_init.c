#include "signals.h"

/**
 * sigset_init - initializes a sigset
 *
 * @set: pointer to the signal set
 * @signals: 0-terminated array of int of SIGNUM
 *
 * Return: 0 on success, -1 on error
 */
int sigset_init(sigset_t *set, int *signals)
{
	int i = 0;

	if (sigemptyset(set) < 0)
		return (-1);

	while (signals[i])
	{
		if (sigaddset(set, signals[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}
