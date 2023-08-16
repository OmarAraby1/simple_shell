#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: concated to
 * @src: concated
 * Return: pointer to result
 */

char *_strcat(char *dest, char *src)
{
	int len1, len2, i, j;

	len1 = _strlen(dest);
	len2 = _strlen(src);
	j = 0;
	i = len1;
	while (i < len1 + len2)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
