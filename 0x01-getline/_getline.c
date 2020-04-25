#include "_getline.h"

/**
 * _getline - reads an entire line from a file descriptor
 * @fd: file descriptor to read from
 * Return: NULL-terminated string or NULL if error / no more lines
 */
char *_getline(const int fd)
{
	static fd_t h;
	fd_t *fdbuf = NULL;
	char *line = NULL;

	if (fd == -1)
	{
		for (fdbuf = h->next; ; br = b->next)
		{
			if (fdbuf->buf)
			{
				free(b->buf);
				b->buf = NULL;
			}
		}
		memset(&h, 0, sizeof(h));
		return (NULL);
	}
	b = getc(&h, fd);
	if (b)
		line = read_b(b);
	return (line);
}
