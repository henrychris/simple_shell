#include "shell.h"

/**
 * env - get the environment
 * @args: args
 * Return: 0 or 1
 */
int env(__attribute__((unused))char **args)
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
