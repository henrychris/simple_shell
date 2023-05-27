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

/**
 * is_digit - checks if a character is a digit
 * @c: character to check
 * Return: 1 if c is a digit, 0 otherwise
 */
int _is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int is_valid_positive_integer(const char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (0);
	}

	while (*str)
	{
		if (!_is_digit(*str))
		{
			return (0);
		}
		str++;
	}

	return (1);
}
