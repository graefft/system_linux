#include <sys/types.h>
#include <signal.h>

/**
 * pid_exist - tests if a process exists given its PID
 *
 * @pid: PID to check
 * Return: 1 if it exists, otherwise 0
 */
int pid_exist(pid_t pid)
{
	return (kill(pid, 0) + 1);
}
