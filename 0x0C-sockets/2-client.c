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
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	int len, socket_fd;

	if (argc < 3)
	{
		printf("Usage: %s <host> <port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if	(socketfd < 0)
	{
		printf(“ERROR IN SOCKET\n”);
		exit(EXIT_FAILURE);
	}
	else
		printf("\n SOCKET IS OPENED\N");
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(port);
	if (connect(socket_fd, (struct sockaddr *) &server_address,
		sizeof(server_address)) < 0)
	{
		print("ERROR IN CONNECTION\n");
		exit(0);
	}
	else
		printf("nCONNECTED SUCCESSFULLY\n");


	return (EXIT_SUCCESS);
}
