#include "utils.h"

/**
 * parse_command - parse a command into an array of strings
 * @command: a string representing a command
 * Return: an array of strings representing the command
 */
char **parse_command(char *command)
{
	int i = 0;
	char **commands = malloc(MAX_ARGC * sizeof(char *));
	char *token = strtok(command, DELIMS);

	if (commands == NULL)
	{
		perror("Malloc failed");
		exit(1);
	}

	while (token != NULL && i < MAX_ARGC)
	{
		commands[i] = token;
		/* Allocate memory for the token and copy its value */
		i++;
		token = strtok(NULL, DELIMS);
	}

	/* Null-terminate the commands array */
	commands[i] = NULL;
	return (commands);
}

/**
 * exec_command - execute a command. First checks for builtins, then
 * ext programs
 * @command: an array of a strings representing parts of a command
 * Return: an int representing success or failure.
 */
int exec_command(char **command)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("Error with fork().");
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(command[0], command, NULL) < 0)
		{
			perror("Error");
			exit(1);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}

	return (0);
}