#include "main.h"

/**
* _string_concat - Concatenates two strings together
*
* @str1: The first string
* @str2: The second string
* Return: The concatenated string
*/

char *_string_concat(char *str1, char *str2)
{
	char *str = str1;

	while (*str1)
		str1++;
	while (*str2)
		*str1++ = *str2++;
	*str1 = *str2;

	return (str);
}
