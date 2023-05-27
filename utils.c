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
 * @line: the line of input from the user
 * Return: an int representing success or failure.
 */
int exec_command(char **command, int count, char *program_name, char *line)
{
	int status, child_pid;
	char *base_command = NULL;

	if (command[0][0] != '.')
	{
		int result = execute_builtin_command(command, count, program_name, line);

		if (result != -1)
			return (result);

		base_command = find_command(command[0]);
		if (base_command == NULL)
		{
			_perror(count, command[0], program_name);
			return (1);
		}
	}
	child_pid = fork();
	if (child_pid < 0)
	{
		perror("Error with fork().");
		exit(-1);
	}
	if (child_pid == 0)
	{
		if (base_command == NULL)
			base_command = command[0];
		if (execve(base_command, command, NULL) < 0)
		{
			_perror(count, command[0], program_name);
			exit(2);
		}
	}
	wait(&status);
	if (WIFEXITED(status))
		exit_code = (WEXITSTATUS(status));
	if (base_command != command[0]) /* if they dont match, base_command was */
		free(base_command);	/* dynamically allocated */
	return (exit_code);
}

/**
 * find_command - find a command in the PATH
 * @command: a string representing a command
 * Return: an int representing success or failure
 */
char *find_command(char *command)
{
	char *path = NULL;
	char *path_copy;
	char *directory;

	path = getenv("PATH");
	if (!path)
	{
		path = PATH;
	}

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

/**
 * execute_builtin_command - execute a builtin command
 * @cmd: an array of a strings representing parts of a command
 * @count: the number of commands executed so far
 * @p_name: the name of the program
 * @line: the line of input from the user
 * Return: an int representing success or failure.
 */
int execute_builtin_command(char **cmd, int count, char *p_name, char *line)
{
	if (_strcmp(cmd[0], "env") == 0)
		return (env());
	else if (_strcmp(cmd[0], "cd") == 0)
		return (cd(count, cmd[1], p_name));
	else if (_strcmp(cmd[0], "exit") == 0)
		return (exit_shell(cmd, line, count, p_name));

	return (-1); /* Indicate that the command is not a built-in command*/
}
