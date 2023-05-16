#include "main.h"

/**
 * main - main function for the shell
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	char *command, path[PATH_MAX], *cmd;

	command = (char *)malloc(1024);
	getcwd(path, sizeof(path));

	if (command == NULL)
	{
		/* print error to stderror */
		return (1);
	}

	while (1)
	{
		printf("$ %s ", path);
		if (fgets(command, 1024, stdin) == NULL)
		{
			/* print error to stderror */
			break;
		}
		/* TODO Trim command input*/
		if (strcmp(command, "exit\n") == 0)
			break;

		cmd = parse_command(command);
		execute_command(cmd);
	}
	free(command);
	return (0);
}

/**
 * parse_command - parses the command
 * @command: command to parse
 * Return: The command to execute
 */
char *parse_command(char *command)
{
	const char delimiters[] = " ,.!><|&;\"'\n";
	char *token = strtok(command, delimiters);

	return (token);
}

void execute_command(char *command)
{
	int (*commandFunctions[])() = {cd, history, env, setenv, unsetenv, help};
	const char *commandNames[] = {"cd", "history", "env", "setenv", "unsetenv", "help"};

	int numCommands = sizeof(commandNames) / sizeof(commandNames[0]);
	int i;

	for (i = 0; i < numCommands; i++)
	{
		if (strcmp(command, commandNames[i]) == 0)
		{
			commandFunctions[i]();
			return;
		}
	}
	printf("Nothing Here.\n");
}
