#include "main.h"

/**
 * main - main function for the shell
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *line = NULL, **cmds = NULL;
	size_t size = 0;

	while (1)
	{
		printf("$ ");
		if (getline(&line, &size, stdin) < 0)
		{
			write(1, "\n", 1);
			free(line);
			return (0);
		}
		cmds = parse_command(line);
		if (!cmds[0])
		{
			free(line);
			free(cmds);
			continue;
		}
		exec_command(cmds);
		free(cmds);
	}
	return (0);
}
