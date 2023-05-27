#include "shell.h"

void func(void);
int exit_code = 0;
/**
 * main - main function for the shell
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
	/* check 1, 2 & 3 passed */
	int count = 1;
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
			exit(exit_code);
		}
		if (line[0] == '\n' || line[0] == '\0')
			continue;

		remwspaces(line);
		cmds = parse_command(line);
		if (!cmds[0])
		{
			free(cmds);
			continue;
		}
		exit_code = exec_command(cmds, count, argv[0], line);
		free(cmds);
		count++;
	}
	return (exit_code);
}

/**
 * func - does literally nothing. seriously.
 * Return: void
 */
void func(void)
{
	/*
	 * seriously don't touch this, let it be.
	 * it fixes a betty issue.
	 */
}
