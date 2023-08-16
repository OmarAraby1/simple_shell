#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: copy it to the memory
 *
 * Return: pointer to the string or NULL
 */
char *_strdup(char *str)
{
	char *newstr;
	int i = 0;
	int l;

	if (str == NULL)
	{
		return (NULL);
	}
	l = _strlen(str) + 1;
	newstr = malloc(sizeof(char) * l);
	while (i < l)
	{
		if (newstr == NULL)
		{
			return (NULL);
		}
		newstr[i] = str[i];
		i++;
	}
	return (newstr);
}
