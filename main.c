#include "shell.h"

/**
 * main - main function for the shell
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
	/* check 1, 2 & 3 passed */
	int count = 0;
	char *line = NULL, **cmds = NULL;
	size_t size = 0;

	while (1)
	{
		/* if the env isnt terminal, '$' isn't printed*/
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		if (getline(&line, &size, stdin) < 0)
		{
			free(line);
			return (0);
		}
		if (line[0] == '\n' || line[0] == '\0')
			continue;
		if (_strcmp(line, "exit\n") == 0)
		{
			free(line);
			return (0);
		}
		cmds = parse_command(line);
		if (!cmds[0])
		{
			free(cmds);
			continue;
		}
		exec_command(cmds, count, argv[0]);
		free(cmds);
		count++;
	}
	return (0);
}
