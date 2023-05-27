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
 * _is_digit - checks if a character is a digit
 * @c: character to check
 * Return: 1 if c is a digit, 0 otherwise
 */
int _is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * is_valid_positive_integer - check stuff
 * @str: a string
 * Return: an int sha
*/
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

/**
 * _write_err - prints a character to stderr
 * @s: string input
 * Return: number of characters printed
 */
int _write_err(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar_err(s[i]);
		i++;
	}

	return (i);
}

/**
 * _putchar_err - writes the character c to stderr
 * @c: The character to print
 * Return: On success 1.
 */
int _putchar_err(char c)
{
	return (write(2, &c, 1));
}
