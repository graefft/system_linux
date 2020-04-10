#include "signals.h"

/**
 * main - prints description of a given signal
 * @argc: number of arguments
 * @argv: arguments, 0 is program name and 1 is SIGNUM
 * Return: 0 on success or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	char *signal_string;

	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	signal_string = strsignal(atoi(argv[1]));
	printf("%s: %s\n", argv[1], signal_string);
	return (0);
}
