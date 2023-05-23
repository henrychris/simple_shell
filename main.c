#include "main.h"

/**
 * main - main function for the shell
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(__attribute__((unused))int argc, char **argv)
{
	char *command = NULL, **cmds;
	int count = 1, ret = 0, j = 0;
	size_t n = 0;

	while (1)
	{
		printf("$ ");
		if (getline(&command, &n, stdin) <= -1)
		{
			free(command);
			command = NULL;
			write(1, "\n", 1);
			return (0);
		}
		if (strcmp(command, "exit\n") == 0)
		{
			free(command);
			command = NULL;
			return (0);
		}

		cmds = parse_command(command);
		ret = exec_command(cmds);
		/* -1 = command not found */
		if (ret == -1)
			print_error(argv[0], count, command);
		/* freeing command */
		n = 0;
		if (command != NULL)
		{
			free(command);
			command = NULL;
		}
		/* freeing cmds */
		for (j = 0; cmds[j] != NULL; j++)
		{
			free(cmds[j]);
			cmds[j] = NULL;
		}
		if (cmds != NULL)
		{
			free(cmds);
			cmds = NULL;
		}
		count++;
	}
	return (0);
}
