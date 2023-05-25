/*
 *#include "main.h"
 *
 *
 *
 *
 *int main(__attribute__((unused)) int argc, char **argv)
 *{
 *	char *line, **cmds = NULL;
 *	size_t size = 0;
 *
 *	while (1)
 *	{
 *		printf("$ ");
 *		if (getline(&line, &size, stdin) < 0)
 *		{
 *			write(1, "\n", 1);
 *			free(line);
 *			return (0);
 *		}
 *		if (strcmp(line, "exit\n") == 0)
 *		{
 *			free(line);
 *			if (cmds)
 *				free(cmds);
 *			exit(0);
 *		}
 *
 *		cmds = parse_command(line);
 *		if (!cmds[0])
 *		{
 *			free(cmds);
 *			continue;
 *		}
 *		exec_command(cmds);
 *		free(cmds);
 *	}
 *	return (0);
 *}
 */
