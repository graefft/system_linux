#include "hls.h"

/**
 * hls - lists directory contents
 * @argc: number of arguments
 * @argv: arguments (directory and/or options)
 * Return: 0 on success, 2 on failure
 */
unsigned int hls(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *dent;
	char *directory = ".";
	int i, space, new_line;
	unsigned int exit_status = 0;

	for (i = 1, space = 0; i < argc || argc == 1; i++, space = 0)
	{
		if (argc > 1)
			directory = argv[i];
		dir = opendir(directory);
		if (dir == NULL)
		{
			exit_status = error_handler(directory);
			continue;
		}
		if (argc > 2)
			printf("%s:\n", argv[i]);
		while ((dent = readdir(dir)) != NULL)
		{
			if (*dent->d_name == '.')
				continue;
			if (space == 1)
				printf(" %s", dent->d_name);
			else
				printf("%s", dent->d_name);
			space = 1;
			new_line = 1;
		}
		if (new_line == 1)
			printf("\n");
		if (argv[i + 1] != NULL && opendir(argv[i + 1]) != NULL)
			printf("\n");
		closedir(dir);
		if (argc == 1)
			break;
	}
	return (exit_status);
}

/**
 * error_handler - handles errors for hls
 * @directory: directory to search in
 * Return: 2 for failure
 */
unsigned int error_handler(char *directory)
{
	char buf[BUFSIZ];

	if (errno == ENOENT)
		sprintf(buf, "hls: cannot access %s", directory);
	else if (errno == EACCES)
		sprintf(buf, "hls: cannot open directory %s", directory);
	perror(buf);
	return (2);
}

/**
 * main - entry point for program
 * @argc: number of arguments
 * @argv: arguments given
 * Return: 0 on success, 2 on failure
 */
int main(int argc, char *argv[])
{
	int exit_status;

	exit_status = hls(argc, argv);
	return (exit_status);
}
