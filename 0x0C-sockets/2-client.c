#include "sockets.h"

/**
 * main - connect to server on port 12345
 *
 * @argc: number of arguments
 * @argv: <host> <port>
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	char hostbuffer[256];
	struct addrinfo hints, *res;
	int socket_fd;

	if (argc < 3)
	{
		fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (gethostname(hostbuffer, 256) != 0)
	{
		perror("gethostname");
		return (EXIT_FAILURE);
	}
	memset(&hints, 0, sizeof(hints));
	if (getaddrinfo(argv[1], argv[2], &hints, &res) != 0)
	{
		perror("getaddrinfo");
		return (EXIT_FAILURE);
	}
	socket_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if	(socket_fd < 0)
	{
		perror("socket");
		return (EXIT_FAILURE);
	}
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = 0;
	hints.ai_flags = AI_NUMERICSERV;
	if (connect(socket_fd, res->ai_addr, res->ai_addrlen) < 0)
	{
		perror("connect");
		exit(1);
	}
	printf("Connected to %s:%s\n", argv[1], argv[2]);
	freeaddrinfo(res);
	close(socket_fd);
	return (EXIT_SUCCESS);
}
