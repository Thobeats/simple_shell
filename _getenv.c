#include "main.h"

/**
* _getenv - Prints out the env variables
* @name: The name of the env variable
* Return: 0 on success, -1 on failure
*/

char *_getenv(char *name)
{
	unsigned int i;
	char *check;
	char *token;


	if (environ == NULL)
	{
		return ("exec failed");
	}

	i = 0;
	while (environ[i] != NULL)
	{
		check = environ[i];
		token = strtok(check, "=");
		if (_strcmp(name, token) == 0)
		{
			token = strtok(NULL, "=");
			break;
		}
		else
		{
			i++;
		}
	}

	return (token);
}
