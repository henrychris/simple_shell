#include "shell.h"

/**
 * _strlen - string length
 * @str: string
 * Return: length of string
 */
size_t _strlen(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strcmp - compare 2 strings
 * @str1: string 1
 * @str2: string 2
 * Return: 0 if equaul and otherwise if not equal
 */
int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (str1[i] - str2[i]);
}

/**
 * _strcpy - string copy of n limit
 * @dest: destination
 * @src: source string
 * Return: sized of char copied
 */
int _strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

/**
 * _strdup - strdup()
 * @s: string
 * Return: duplicate of s
 */
char *_strdup(char *s)
{
	size_t len = _strlen(s) + 1;
	char *new_str = malloc(len);

	if (new_str == NULL)
	{
		return (NULL);
	}
	_memcpy(new_str, s, len);

	return (new_str);
}

/**
 * _strcat - concatenate 2 strings
 * @dest: destination string
 * @src: source string
 * Return: concatenated string
 */
char *_strcat(char *dest, const char *src)
{
	char *p = dest;
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		p[i] = src[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}
