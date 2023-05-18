#include "main.h"

/**
 * main - main function for the shell
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	char *command = NULL, *path = NULL, *cmd;
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

		cmd = parse_command(command);
		ret = execute_buitin_cmd(cmd);
		if (ret == -1)
			print_notfound_error(argv[0], count, command);
		count++;
	}
	free(path);
	free(command);
	return (0);
}

/**
 * print_notfound_error - print error message
 * @argVector: argv
 * @count: count it
 * @command: command
 */
void print_notfound_error(char *argVector, int count, char *command)
{
	char *string = malloc(sizeof(char) * (strlen(command)));
	int i = 0;
	char numberString[10];

	sprintf(numberString, "%d", count);
	write(STDERR_FILENO, argVector, strlen(argVector));
	write(STDERR_FILENO, ": ", 2);
	while (numberString[i] != '\0')
		i++;
	write(STDERR_FILENO, numberString, i);
	i = 0;
	write(STDERR_FILENO, ": ", 2);
	while (command[i] != '\n' && command[i] != '\0')
	{
		string[i] = command[i];
		i++;
	}
	write(STDERR_FILENO, string, i);
	write(STDERR_FILENO, ": not found\n", 12);
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

	/*
	 * for now, only return the first token
	 * In the future, store all tokens in an array or linked list.
	 */
	return (token);
}

int execute_buitin_cmd(char *command)
{
	/*
	 * Instead of a an if-else or switch statement
	 * Functions are stored in an array of pointers to functions
	 * If found in arrray of commandNames, the index is used to execute the function.
	 */
	int (*commandFunctions[])() = {cd, history, env, setenv, unsetenv, help};
	const char *commandNames[] = {"cd", "history", "env", "setenv", "unsetenv", "help"};

	int numCommands = sizeof(commandNames) / sizeof(commandNames[0]);
	int i;

	for (i = 0; i < numCommands; i++)
	{
		// check if command exists in our array of command names
		if (strcmp(command, commandNames[i]) == 0)
		{
			return (commandFunctions[i]());
		}
		// if not found, try to get ext function
	}
	/* Returns a value so we can return an error */
	return (execute_ext_cmd(command));
}
