#include "shell.h"

/**
 * env - get the environment
 * Return: Always succeeds
 */
int env(void)
{
	char **env = environ;

	while (*env)
	{
		write(1, *env, strlen(*env));
		write(1, "\n", 1);
		env++;
	}
	return (0);
}

/**
 * cd - changes the current working directory
 * @args: args
 * @count: count
 * @program_name: p_name
 * Return: 0 on success, 1 on failure
 */
int cd(int count, char *args, char *program_name)
{
	char *dirName = args;

	if (dirName == NULL)
	{
		dirName = getenv("HOME");
		if (!dirName)
			_perror_cd(count, "/root", program_name);
	}
	else if (strcmp(dirName, "-") == 0)
	{
		dirName = getenv("OLDPWD");
		if (!dirName)
			_perror_cd(count, "OLDPWD", program_name);
	}
	if (chdir(dirName) != 0)
		_perror_cd(count, dirName, program_name);
	else
	{
		if (setenv("PWD", dirName, 1) != 0)
			_perror_cd(count, dirName, program_name);
	}
	return (0);
}

/**
 * _perror_cd - perror cd
 * @count: count
 * @command: command
 * @program_name: p_name
 */
void _perror_cd(int count, char *command, char *program_name)
{
	_write(program_name);
	_write(": ");
	write_number(count, 1);
	_write(": cd: can't cd to ");
	_write(command);
	_write("\n");
}

/**
 * exit_shell - exit the shell
 * @command: command
 * @line: line of input
 * @count: count
 * @program_name: p_name
 * Return: void
 */
int exit_shell(char **command, char *line, int count, char *program_name)
{
	int status;

	if (command[1])
	{
		if (!is_valid_positive_integer(command[1]))
		{
			_write_err(program_name);
			_write_err(": ");
			write_number(count, 2);
			_write_err(": ");
			_write_err(command[0]);
			_write_err(": ");
			_write_err("Illegal number: ");
			_write_err(command[1]);
			_write_err("\n");
			return (2);
		}
		status = _atoi(command[1]);
		free(line);
		free(command);
		exit(status);
	}
	free(line);
	free(command);
	exit(exit_code);
}
