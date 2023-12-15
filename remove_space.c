#include "main.h"

/**
 * remove_space - This removes space from the command
 *
 * @path: a pointer to the path
 *
 * Return: the sorted string
 */

char *remove_space(char *path)
{
	int i;
	char *result = NULL;

	if (path == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (path[i] != '\0')
	{
		if (!isspace(path[i]))
			result[i] = path[i];
		i++;
	}

	return (result);
}
