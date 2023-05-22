#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *_strlite(char *string, const char *delim)
{
	int j = 0, i = 0, stop = 0;
	char *str = malloc((strlen(string) + 1) * sizeof(char));

	strcpy(str, string);
	if (str == NULL)
		return (NULL);
	while (str[j] != '\0')
	{
		for (i = 0; i < strlen(delim); i++)
		{
			if (str[j] == delim[i])
			{
				str[j] = '\0';
				stop = 1;
				break;
			}
		}
		if (stop == 1)
			break;
		j++;
	}
	return (str);
}
char *_strtok(char *str, const char *delim)
{
	int i = 0;
	static char *p = NULL;
	char *ptr;

	if (str == NULL)
	{
		if (p == NULL || p[i] == '\0')
			return (NULL);
		while (1)
		{
			if (p[i] == '\0')
			{
				ptr = &p[i + 1];
				break;
			}
			i++;
		}
	} else
	{
		ptr = str;
		if (p != NULL)
			free(p);
		p = malloc(1024 * sizeof(char));
		if (p == NULL)
		{
			perror("Fail");
			return (NULL);
		}
	}
	p = _strlite(ptr, delim);
	return (p);
}
int main(void)
{
	char s[] = "Hello,my,name,is,Adam";
	char *ptr;

	ptr = _strtok(s, ",");
	while (ptr)
	{
		printf("%s\n", ptr);
		ptr = _strtok(NULL, ",");
	}
	return (0);
}
