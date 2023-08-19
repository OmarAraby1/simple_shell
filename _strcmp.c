#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: pointer to stirng one
 * @s2: pointer to string two
 * Return: None
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
