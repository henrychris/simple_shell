#include "utils.h"

/**
 * parse_command - parses the command and tokenises it
 * @command: command to parse
 * Return: An array consisting of command and arguments (if any)
 */
char **parse_command(char *command)
{
	int i = 0;
	char *token = strtok(command, DELIMS);
	char **commands = malloc(MAX_ARGC * sizeof(char *));

	if (command == NULL)
		return (NULL);
	while (token != NULL && i < MAX_ARGC)
	{
		/* Allocate memory for the token and copy its value */
		commands[i] = malloc(strlen(token) + 1);
		strcpy(commands[i], token);

		i++;
		token = strtok(NULL, DELIMS);
	}
	/* Null-terminate the commands array */
	commands[i] = NULL;

	/* if i < MAX_ARGC, free unused but allocated memory */
	while (i < MAX_ARGC)
	{
		free(commands[i]);
		i++;
	}
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
	int (*commandFunctions[])(char **) = {exit_sh, cd, history, env, pwd};
	const char *commandNames[] = {"exit", "cd", "history", "env", "pwd"};

	int numCommands = sizeof(commandNames) / sizeof(commandNames[0]);
	int i = 0;
	/* the main command is the first item in the array */
	char *base_command = command[i];

	for (i = 0; i < numCommands; i++)
	{
		/* check if command exists in our array of command names */
		if (strcmp(base_command, commandNames[i]) == 0)
		{
			/* The param is passed to the function that requires it */
			return (commandFunctions[i](command));
		}
	}

	/* if not found, try to run externa; function */
	return (execute_ext_cmd(base_command, command));
}
/**
 * execute_ext_cmd - execute external programs
 * @base_command: the program being called, the first arg
 * in args
 * @args: an array of strings, tokenised from the original command
 * Return: an int value representing success or failure
 */
int execute_ext_cmd(char *base_command, char **args)
{
	pid_t pid;
	int status = 0;
	char *envp[] = {NULL};

	pid = fork();
	if (pid == -1)
		return (-2);
	/* TODO processing error? */
	/* maybe use the stderror codes? */
	if (pid == 0)
	{
		execve(base_command, args, envp);
		return -1;
	}

	/* wait for child process to execute */
	waitpid(pid, &status, 0);
	return (status);
}

/**
 * print_error - print error message
 * @argVector: argv
 * @count: count it
 * @command: command
 * Return: nothing
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

	free(string);
}

/**
 * _getline - out getline function
 * @lineptr: lineptr
 * @n: size of line
 * @stream: stream
 * Return: ssize_t
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t count = 1024;
	ssize_t size = 0;

	if (*n == 0 && stream)
	{
		/* free previous memory before use */
		if (*lineptr != NULL)
		{
			free(*lineptr);
			*lineptr = NULL;
		}

		*lineptr = malloc(count * sizeof(char *));
		if (!(*lineptr))
		{
			perror("File");
			return (1);
		}
		size = read(0, *lineptr, count);
		if (size == -1)
		{
			perror("File");
			return (1);
		}
	}
	return (0);
}