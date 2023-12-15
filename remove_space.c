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
	int i = 0, j = 0;
	char *result;

	if (path == NULL)
	{
		return (NULL);
	}
	/** Allocate memory for the result string */
	result = malloc(strlen(path) + 1);
	if (result == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	while (path[i] != '\0')
	{
		if (!isspace(path[i]))
		{
			result[j] = path[i];
			j++;
		}
		i++;
	}

	/** Null-terminate the result string */
	result[j] = '\0';

	return (result);
}
