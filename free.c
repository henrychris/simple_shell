// #include "utils.h"

// /**
//   * free_double_ptr - free **ptr
//   * @ptr: ptr
//   */
// void free_double_ptr(char ***ptr)
// {
// 	int i;
// 	char **p = *ptr;

// 	if (*ptr != NULL)
// 	{
// 		for (i = 0; p[i] != NULL; i++)
// 		{
// 			free(p[i]);
// 			p[i] = NULL;
// 		}
// 		free(*ptr);
// 		*ptr = NULL;
// 	}
// }

// /**
//   * free_ptr - free *ptr
//   * @command_ptr: command_ptr
//   */
// void free_ptr(char **command_ptr)
// {
// 	if (*command_ptr != NULL)
// 	{
// 		free(*command_ptr);
// 		*command_ptr = NULL;
// 	}
// }
