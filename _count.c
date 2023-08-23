#include "main.h"

/**
 * _count - count words
 * @s: string to count
 * Return: number of words
 */

size_t _count(char *s)
{
	int i;
	int count = 0;
	int state = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			state = 0;
		}
		else if (state == 0)
		{
			state = 1;
			count++;
		}
	}
	return (count);
}
