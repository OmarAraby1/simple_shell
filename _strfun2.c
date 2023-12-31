#include "main.h"

/**
 * _strchr - Locates a character in a string
 * @s: The string to be searched
 * @c: The character to be located
 * Return: pointer to c or NULL
 */

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	return (NULL);
}

/**
 * _strspn - Gets the length of a prefix substring
 * @s: The string to be searched
 * @acc: The prefix to be measured
 * Return: The number of bytes
 */

int _strspn(char *s, char *acc)
{
	int bytes = 0;
	int i;

	while (*s)
	{
		for (i = 0; acc[i]; i++)
		{
			if (*s == acc[i])
			{
				bytes++;
				break;
			}
		}
		s++;
	}
	return (bytes);
}

/**
 * _strcmp - Compares two strings
 * @s1: The first string to be compared
 * @s2: The second string to be compared
 * Return: +ve or 0 or -ve
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * _strncmp - Compare two strings
 * @s1: Pointer to a string
 * @s2: Pointer to a string
 * @n: The first n bytes of the strings to compare
 * Return: -ve or 0 or +ve
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-15);
}
