#include "main.h"

/**
 * _tokenize - turn string into tokenz
 * @str: the buffer
 * @delim: delimeter
 * Return: pointer to tokenized list
 */
char **_tokenize(char *str, const char *delim)
{
	int len = 0, nlet = 0, i = 0;
	char **toklist = NULL;
	char *str2 = NULL;
	char *tok = NULL;

	str2 = malloc(sizeof(char *) + _strlen(str));
	if (str2 == NULL)
	{
		perror("Error");
		free(str2);
	}
	while (str[len] != '\0')
	{
		if (str[len] == '\n')
			str[len] = '\0';
		if (str[len] != delim[0])
			nlet++;
		len++;
	}
	str2 = _strcpy(str2, str);
	toklist = malloc((sizeof(char *) * (nlet + 1)));
	if (toklist == NULL)
	{
		perror("Error");
		free(toklist);
	}
	tok = strtok(str2, delim);
	while (tok)
	{
		toklist[i] = malloc(sizeof(char) * ((_strlen(tok)) + 1));
		if (toklist[i] == NULL)
			_free(toklist);
		_strcpy(toklist[i], tok);
		i++;
		tok = strtok(NULL, delim);
	}
	toklist[i] = NULL;
	free(str2);
	return (toklist);
}
