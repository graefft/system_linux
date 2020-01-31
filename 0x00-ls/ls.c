#include "hls.h"

int hls(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *dent;
	char *directory = ".";
	int i = 1;

	while (i < argc || argc == 1)
	{
		
		if (argc > 1)
			directory = argv[i];
		dir = opendir(directory);
		if (dir == NULL)
		{
			write(2, "hls: cannot open directory", 26);
			perror(argv[i]);
			exit(2);
		}
		while ((dent = readdir(dir)) != NULL)
		{
			printf("%s ", dent->d_name);
		}
		printf("\n");
		closedir(dir);
		i++;
		if (argc == 1)
			break;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int exit_status;

	exit_status = hls(argc, argv);
	return (exit_status);
}
