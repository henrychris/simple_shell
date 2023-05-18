#include "main.h"

/**
 * main - main function for the shell
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	char *command = NULL, *path = NULL, **cmds;
	int i = 0, count = 1, ret = 0;
	size_t n = 0;

	path = malloc(PATH_MAX);
	if (path == NULL)
		return (-1);

	if (getcwd(path, PATH_MAX) == NULL)
		return (-1);

	while (1)
	{
		printf("$ ");
		i = getline(&command, &n, stdin);
		if (strcmp(command, "exit\n") == 0 || i == EOF)
		{
			if (i == -1)
				write(1, "\n", 1);
			break;
		}

		cmds = parse_command(command);
		ret = exec_command(cmds);
		if (ret == -1)
			print_error(argv[0], count, command);
		count++;
	}
	free(path);
	free(command);
	return (0);
}