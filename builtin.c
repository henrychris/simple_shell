#include "main.h"
#include "utils.h"

extern char **environ;
/**
 * cd - changes the current working directory
 * Return: 0 on success, 1 on failure
 */
int cd(char **args)
{
	char *dirName = args[1];

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

/**
 * history - show history
 * Return: 0, or 1
 */
int history(void)
{
	return (0);
}

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
 * help - show help
 * Return: 0 or 1
 */
int help(void)
{
	return (0);
}

/**
 * pwd - print the current directory
 * Return: 0 or 1
 */
int pwd(void)
{
	char *buff = malloc(sizeof(char) * PATH_MAX);
	if (getcwd(buff, PATH_MAX) == NULL)
	{
		perror("Error with getcwd() in pwd(void)");
		return (-2);
	}

	write(1, buff, strlen(buff) + 1);
	write(1, "\n", 1);

	free(buff);
	return (0);
}