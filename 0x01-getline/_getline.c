#include "_getline.h"

/**
 * _getline - reads an entire line from a file descriptor
 * @fd: file descriptor to read from
 * Return: NULL-terminated string or NULL if error / no more lines
 */
char *_getline(const int fd)
{
	static fd_t head;
	fd_t *buffer = NULL;
	char *line = NULL;

	if (fd == -1)
	{
		for (buffer = head->next; buffer; buffer = buffer->next)
		{
			if (buffer->buf)
			{
				free(buffer->buf);
				buffer->buf = NULL;
			}
		}
		memset(&head, 0, sizeof(head));
		return (NULL);
	}
	buffer = get_fd(&head, fd);
	if (buffer)
		line = read_buf(buffer);
	return (line);
}
