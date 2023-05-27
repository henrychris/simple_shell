#include "shell.h"
#define PATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

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
 * @count: the number of commands executed so far
 * @program_name: the name of the program
 * Return: an int representing success or failure.
 */
int exec_command(char **command, int count, char *program_name)
{
	int status, child_pid;
	char *cmd = NULL;

	if (command[0][0] != '.')
	{
		if (_strcmp(command[0], "env") == 0)
		{
			env();
			return (0);
		} else if (_strcmp(command[0], "cd") == 0)
		{
			cd(command[1]);
			return (0);
		}
		cmd = find_command(command[0]);
		if (cmd == NULL)
		{
			_perror(count, command[0], program_name);
			return (1);
		}
	}
	child_pid = fork();
	if (child_pid < 0)
	{
		perror("Error with fork().");
		exit(1);
	}
	if (child_pid == 0)
	{
		if (cmd == NULL)
			cmd = command[0];
		if (execve(cmd, command, NULL) < 0)
		{
			_perror(count, command[0], program_name);
			exit(1);
		}
	}
	else
		waitpid(child_pid, &status, 0);
	return (0);
}

/**
 * find_command - find a command in the PATH
 * @command: a string representing a command
 * Return: an int representing success or failure
 */
char *find_command(char *command)
{
	char *path = PATH;
	char *path_copy;
	char *directory;

	if (!path)
		return (NULL);

	if (access(command, X_OK) == 0)
		return (command);

	path_copy = _strdup(path);
	directory = strtok(path_copy, ":");

	while (directory)
	{
		char full_path[1024];

		_strcpy(full_path, directory);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			/* printf("Found command: %s\n", full_path); */
			free(path_copy);
			return (_strdup(full_path));
		}
		directory = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
