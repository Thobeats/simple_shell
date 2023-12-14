#include "main.h"

/**
 * _prompt - Prompts the user to enter some values
 * @name: The name of the program
 * Return: 1 on success
 */

int _prompt(char **name)
{
	char *prompt = "$ ";
	ssize_t response = 0;

	response = write(STDOUT_FILENO, prompt, _strcount(prompt));
	if (response < 0)
	{
		free((*name));
		perror("ERROR: write failed \n");
		return (-1);
	}

	return (1);
}
