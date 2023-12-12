#include "main.h"

/**
 * _strcmp - compares two strings
 *
 * @s1: First String
 * @s2: Second String
 *
 * Return: copy string
 */

char _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

