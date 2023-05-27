#include "shell.h"

/**
 * env - get the environment
 * Return: 0 or 1
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
 * Return: 0 on success, 1 on failure
 */
int cd(char *args)
{
	char *dirName = args;

	if (dirName == NULL)
	{
		dirName = getenv("HOME");
		if (!dirName)
			perror("Fail");
	}
	else if (strcmp(dirName, "-") == 0)
	{
		dirName = getenv("OLDPWD");
		if (!dirName)
			perror("Fail");
	}
	if (chdir(dirName) != 0)
		perror("Fail");
	else
	{
		if (setenv("PWD", dirName, 1) != 0)
			perror("Fail");
	}
	return (0);
}
