#include "main.h"

/**
 * main - main function for the shell
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *command = NULL, **cmds;
	int count = 1, ret = 0;
	size_t n = 0;

	while (1)
	{
		printf("$ ");
		if (getline(&command, &n, stdin) <= -1)
		{
			free_ptr(&command);
			write(1, "\n", 1);
			return (0);
		}
		if (strcmp(command, "exit\n") == 0)
		{
			free_ptr(&command);
			exit(0);
		}
		cmds = parse_command(command);
		ret = exec_command(cmds);
		if (ret == 1)
			print_error(argv[0], count, command);
		n = 0;
		count++;
		free_double_ptr(&cmds);
	}
	free_double_ptr(&cmds);
	free_ptr(&command);
	return (0);
}
