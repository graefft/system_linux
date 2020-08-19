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
	struct sockaddr_in server;
	struct hostent *host;
	int socket_fd;

	if (argc < 3)
	{
		printf("Usage: %s <host> <port>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	host = gethostbyname(argv[1]);
	if (!host)
		return (EXIT_FAILURE);

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if	(socket_fd < 0)
	{
		printf("ERROR IN SOCKET\n");
		return (EXIT_FAILURE);
	}
	server.sin_family = AF_INET;
	server.sin_addr.s_addr =
		inet_addr(inet_ntoa(*(struct in_addr *)host->h_addr));
	server.sin_port = htons(atoi(argv[2]));
	if (connect(socket_fd, (struct sockaddr *) &server,
		sizeof(server)) < 0)
	{
		printf("ERROR IN CONNECTION\n");
		exit(0);
	}
	printf("Connected to %s:%s\n", argv[1], argv[2]);
	close(socket_fd);
	return (EXIT_SUCCESS);
}
