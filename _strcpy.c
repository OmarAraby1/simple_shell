#include "main.h"

/**
 * _strcpy - copy string to buffer
 * @dest: buffer
 * @src: string
 * Return: the buffer
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (src[i] != '\0')
	{
		i++;
	}
	for (; src[j] != '\0'; j++)
	{
		dest[j] = src[j];
	}
	dest[j] = '\0';
	return (dest);
}
