#include "main.h"

extern char **environ;
/**
 * cd - changes the current working directory
 * Return: 0 on success, 1 on failure
 */
int cd(void)
{
	/* To take arguments from util.c file I'll add new function that
	   takes them and return it to cd */
	/* Argument that I want is name of the directory that I want to change
	   to it */
	printf("Changed Directories.\n");
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
