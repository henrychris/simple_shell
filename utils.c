#include "utils.h"

/**
 * parse_command - parses the command
 * @command: command to parse
 * Return: The command to execute
 */
char **parse_command(char *command)
{
	int i = 0;
	char *token = strtok(command, DELIMS);
	char **commands = malloc(MAX_ARGC * sizeof(char *));

	while (token != NULL && i < MAX_ARGC)
	{
		// Allocate memory for the token and copy its value
		commands[i] = malloc(strlen(token) + 1);
		strcpy(commands[i], token);

		i++;
		token = strtok(NULL, DELIMS);
	}
	/* Null-terminate the commands array*/
	commands[i] = NULL;
	return (commands);
}

int exec_command(char **command)
{
	int (*commandFunctions[])() = {cd, history, env, setenv, unsetenv, help};
	const char *commandNames[] = {"cd", "history", "env", "setenv", "unsetenv", "help"};

	int numCommands = sizeof(commandNames) / sizeof(commandNames[0]);
	int i;
	char* base_command = command[i];

	for (i = 0; i < numCommands; i++)
	{
		// check if command exists in our array of command names
		if (strcmp(base_command, commandNames[i]) == 0)
		{
			return (commandFunctions[i]());
		}
	}

	/* if not found, try to get ext function */
	return (execute_ext_cmd(command[i], command));
}

int execute_ext_cmd(char *command, char **args)
{
	// use execve to find program and execute it.
	// make sure to fork and run it in a new process

	// if not found, throw error
	// ! We will decide on error codes.
	return (-1);
}

/**
 * print_notfound_error - print error message
 * @argVector: argv
 * @count: count it
 * @command: command
 */
void print_error(char *argVector, int count, char *command)
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