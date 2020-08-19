#include "sockets.h"

#define port 12345

/**
 * accept_connection - accepts entering connection and prints IP of client
 *
 * @socket_fd: original socket
 * Return: 0 success -1 failure
 */
int accept_connection(int socket_fd)
{
	int data_socket;
	struct sockaddr_in client;
	socklen_t client_len;

	client_len = sizeof(client);
	data_socket = accept(socket_fd, (struct sockaddr *) &client,
				(socklen_t *) &client_len);
	if (data_socket < 0)
	{
		perror("accept");
		return (-1);
	}
	printf("Client connected: %s\n", inet_ntoa(client.sin_addr));
	return (0);
}

/**
 * bind_socket - assigns address with bind()
 *
 * @socket_fd: fd of created socket
 * Return: status or -1 on failure
 */
int bind_socket(int socket_fd)
{
	int status = -1;
	struct sockaddr_in rem;

	memset(&rem, 0, sizeof(rem));
	rem.sin_family = AF_INET;
	rem.sin_addr.s_addr = htonl(INADDR_ANY);
	rem.sin_port = htons(port);
	status = bind(socket_fd, (struct sockaddr *)&rem, sizeof(rem));
	if (status < 0)
	{
		perror("bind");
		return (-1);
	}
	return (status);
}


/**
 * main - opens IPv4/TCP socket and listens on port 12345 and accepts
 *
 * Return: EXIT_SUCCESS or -1
 */
int main(void)
{
	int socket_fd;

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd < 0)
	{
		printf("I don't think that socket creation worked\n");
		return (EXIT_FAILURE);
	}

	if (bind_socket(socket_fd) < 0)
		return (EXIT_FAILURE);

	listen(socket_fd, 3);
	printf("Server listening on port %d\n", port);

	if (accept_connection(socket_fd) < 0)
		return (EXIT_FAILURE);

	close(socket_fd);
	return (EXIT_SUCCESS);
}
