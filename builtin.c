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
