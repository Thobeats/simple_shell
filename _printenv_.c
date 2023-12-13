#include "main.h"

/**
* _printenv - Prints out the env variables
*/

void _printenv(void)
{
	unsigned int i;
	char *nl = "\n";


	if (environ == NULL)
	{
		perror("Enviroment not found");
		return;
	}

	i = 0;
	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strcount(environ[i]));
		write(STDOUT_FILENO, nl, 1);

		i++;
	}

}
