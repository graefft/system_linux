#include "sockets.h"

#define port 12345

/**
 * bind_socket - assigns address with bind()
 *
 * @sock_id: fd of created socket
 * Return: status or -1 on failure
 */
int bind_socket(int sock_id)
{
	int status = -1;
	struct sockaddr_in remote;

	remote.sin_family = AF_INET;
	remote.sin_addr.s_addr = htonl(INADDR_ANY);
	remote.sin_port = htons(port);
	status = bind(sock_id, (struct sockaddr *)&remote, sizeof(remote));

	return (status);
}


/**
 * main - opens IPv4/TCP socket and listens on port 12345
 *
 * Return: EXIT_SUCCESS or -1
 */
int main(void)
{
	int status, sock_id;

	sock_id = socket(AF_INET, SOCK_STREAM, 0);
	if (sock_id == -1)
	{
		perror("socket");
		return (EXIT_FAILURE);
	}
	status = bind_socket(sock_id);
	if (status == -1)
	{
		perror("bind");
		return (EXIT_FAILURE);
	}
	listen(sock_id, 3);
	printf("Server listening on port %d\n", port);
	pause();
	return (EXIT_SUCCESS);
}
