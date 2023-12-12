#include "main.h"

/**
 * _strcount - Counts the number of string available
 *
 * @str: The string to be counted
 *
 * Return: The length of the String
 */

int _strcount(char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;

	return (length);
}
