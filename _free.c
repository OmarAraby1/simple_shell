#include "main.h"

/**
 * _free - frees a string of strings
 * @pp: pointer to pointer
 * Return: NOTHING
 */

void _free(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}
