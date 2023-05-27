#include "shell.h"

/* you can't have too many util classes lmao*/

/**
 * isCharInString - checks if char is in string
 * @str: string
 * @c: char
 * Return: 1 if char is in string, 0 otherwise
 */
int isCharInString(const char *str, char c)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * remwspaces - removes extra whitespaces
 * @s: string
 * Return: str w/o whitespace
 */
void remwspaces(char *s)
{
	int length = _strlen(s);
	int i = 0, j = length - 1, k;
	int l, count, m;

	if (s == NULL)
		return;

	while (i < length && wspace(s[i]))
	{
		i++;
	}
	while (j >= i && wspace(s[j]))
	{
		j--;
	}
	k = 0;
	while (i <= j)
	{
		s[k++] = s[i++];
	}
	s[k] = '\0';
	l = 0;
	count = 0;
	for (m = 0; m <= j; m++)
	{
		if (s[m] != ' ')
		{
			s[l++] = s[m];
			count = 0;
		}
		else if (count == 0)
		{
			s[l++] = s[m];
			count++;
		}
	}
	s[l] = '\0';
}

/**
 * wspace - checks if char is a whitespace
 * @s: char
 * Return: 1 if true, 0 if false
 */
int wspace(char s)
{
	if (s == ' ' || s == '\t')
		return (1);

	return (0);
}

/**
 * _strtok - strtok implementation
 * @str: string
 * @delim: delimiter
 *
 * Return: token
 */
char *_strtok(char *str, char const *delim)
{
	static char *ptr;
	int size = 0;
	char *token;
	int i = 0;

	if (str != NULL)
		ptr = str;
	while (ptr[i] != '\0')
		if (isCharInString(delim, ptr[i]) == 1)
		{
			ptr[i] = '\0';
			token = ptr;
			ptr = &ptr[i + 1];
			return (token);
		}
		else
			i++;
	if (ptr[0] != '\0')
	{
		while (ptr[size] != 0)
			size++;
		token = ptr;
		ptr += size; /* update ptr to '\0' */
		return (token);
	}
	return (NULL);
}
