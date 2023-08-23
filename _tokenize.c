#include "main.h"

/**
 * token_len - Locates the delimiter index
 * @str: The string to be searched
 * @delim: The delimiter character
 * Return: The delimiter index
 */

int token_len(char *str, char *delim)
{
	int i = 0, len = 0;

	while (*(str + i) && *(str + i) != *delim)
	{
		len++;
		i++;
	}
	return (len);
}

/**
 * count_tokens - Counts the number of words
 * @str: The string to be searched
 * @delim: The delimiter character
 * Return: The number of words
 */

int count_tokens(char *str, char *delim)
{
	int i, tok = 0, len = 0;

	for (i = 0; *(str + i); i++)
		len++;

	for (i = 0; i < len; i++)
	{
		if (*(str + i) != *delim)
		{
			tok++;
			i += token_len(str + i, delim);
		}
	}
	return (tok);
}

/**
 * _strtok - Tokenizes a string
 * @str: The string
 * @delim: The delimiter character
 * Return: A pointer to an array of tokens
 */

char **_strtok(char *str, char *delim)
{
	char **ptr;
	int i = 0, tok, t, lets, l;

	tok = count_tokens(str, delim);
	if (tok == 0)
		return (NULL);
	ptr = malloc(sizeof(char *) * (tok + 2));
	if (!ptr)
		return (NULL);
	for (t = 0; t < tok; t++)
	{
		while (str[i] == *delim)
			i++;
		lets = token_len(str + i, delim);
		ptr[t] = malloc(sizeof(char) * (lets + 1));
		if (!ptr[t])
		{
			for (i -= 1; i >= 0; i--)
				free(ptr[i]);
			free(ptr);
			return (NULL);
		}
		for (l = 0; l < lets; l++)
		{
			ptr[t][l] = str[i];
			i++;
		}
		ptr[t][l] = '\0';
	}
	ptr[t] = NULL;
	ptr[t + 1] = NULL;
	return (ptr);
}
