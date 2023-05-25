#include "shell.h"

/**
 * main - main function for the shell
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
	char *line = NULL, **cmds = NULL;
	size_t size = 0;

	while (1)
	{
		/* if the env isnt terminal, '$' isn't printed*/
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		if (getline(&line, &size, stdin) < 0)
		{
			write(1, "\n", 1);
			free(line);
			return (0);
		}
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			continue;
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
