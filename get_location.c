#include "main.h"

/**
 * get_location - Gets the path of the command
 *
 * @command: the command
 *
 * Return: The path of the command
 */

char *get_location(char *command)
{
	char *path, *pathcpy, *token, *filepath;
	int command_length, directory_length;
	struct stat buff;

	path = _getenv("PATH");
	if (path)
	{
		pathcpy = strdup(path);
		command_length = _strcount(command);
		token = strtok(pathcpy, ":");
		while (token != NULL)
		{
			directory_length = _strcount(token);
			filepath = malloc(directory_length + command_length + 2);
			strcpy(filepath, token);
			strcat(filepath, "/");
			strcat(filepath, command);
			strcat(filepath, "\0");

			if (stat(filepath, &buff) == 0)
			{
				free(pathcpy);
				return (filepath);
			}
			else
			{
				free(filepath);
				token = strtok(NULL, ":");
			}
		}
		free(pathcpy);
		if (stat(command, &buff) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}


