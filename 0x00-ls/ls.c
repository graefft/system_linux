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
	char buf[BUFSIZ];
	char *directory = ".";
	int i = 1;

	for (i = 1; i < argc || argc == 1; i++)
	{
		if (argc > 1)
			directory = argv[i];
		dir = opendir(directory);
		if (dir == NULL)
		{
			if (errno == ENOENT)
				sprintf(buf, "hls: cannot access %s", directory);
			else if (errno == EACCES)
				sprintf(buf, "hls: cannot open directory %s", directory);
			perror(buf);
			exit(2);
		}
		while ((dent = readdir(dir)) != NULL)
		{
			if (*dent->d_name == '.')
				continue;
			printf("%s ", dent->d_name);
		}
		printf("\n");
		closedir(dir);
		if (argc == 1)
			break;
	}
	return (0);
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
