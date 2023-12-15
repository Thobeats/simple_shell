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
	int i, j;
	char *result;

	if (path == NULL)
	{
		return (NULL);
	}

	i = 0;
	j = 0;
	result = malloc(sizeof(char) * _strcount(path) + 1);
	while (path[i] != '\0')
	{
		if (!isspace(path[i]))
		{
			result[j] = path[i];
			j++;
		}
		i++;
	}

	result[j] = '\0';

	return (result);
}
