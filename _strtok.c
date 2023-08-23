#include "main.h"

/**
 * is_delim - check for the delimeter
 * @c: the char to check
 * @delim: the delimeter
 * Return: 1 if sucess
 */

unsigned int is_delim(char c, char *delim)
{
    while(*delim != '\0')
    {
        if(c == *delim)
            return 1;
        delim++;
    }
    return 0;
}

/**
 * _strtok - my version of strtok
 * @str: string to be tokenized
 * @delim: the delimeter
 * Return: pointer to tokenized list
 */

char *_strtok(char *str, char *delim)
{
	static char *str2;
	char *ret;

	if(!str)
	{
		str = str2;
	}
	if(!str)
	{
		return (NULL);
	}
	while(1)
	{
		if(is_delim(*str, delim))
		{
			str++;
			continue;
		}
		if(*str == '\0')
		{
			return (NULL); 
		}
		break;
	}
	ret = str;
	while(1)
	{
		if(*str == '\0')
		{
			str2 = str;
			return ret;
		}
		if(is_delim(*str, delim))
		{
			*str = '\0';
			str2 = str + 1;
			return ret;
		}
		str++;
	}
}
