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
	char *path;
	char *pathcpy;

	path = _getenv("PATH");
	pathcpy = strdup(path);
	command = "kk";

	return (pathcpy);

	return (command);
}


