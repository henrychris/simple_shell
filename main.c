#include "main.h"

/**
 * main - main function for the shell
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *command = NULL, **cmds = NULL;
	int i = 0, count = 1, ret = 0;
	size_t n = 0;

	while (1)
	{
		write(1, "$ ", 2);
		i = _getline(&command, &n, stdin);
		if (strcmp(command, "exit\n") == 0 || i == EOF)
		{
			if (i == -1)
				write(1, "\n", 1);
			free(command);
			exit(0);
		}

		cmds = parse_command(command);
		ret = exec_command(cmds);
		/* -1 = command not found */
		if (ret == -1)
			print_error(argv[0], count, command);
		count++;
	}
	free(command);
	free(cmds);
	return (0);
}
