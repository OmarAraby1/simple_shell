#include "main.h"

/**
 * _strlen - length of string
 * @s: the string
 * Return: the length
 */

size_t _strlen(char *s)
{
	size_t i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
