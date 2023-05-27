#include "shell.h"

/**
 * _atoi - convert a string to an integer
 * @str: string to convert to an int
 * Return: integer value of str
 */
int _atoi(const char *str)
{
	int i, n = 0;
	int sign = 1;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '-')
			sign = -1;
		else if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 + (str[i] - '0');
		else
			break;
	}

	return (n * sign);
}
