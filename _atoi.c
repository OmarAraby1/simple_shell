#include "main.h"

/**
 * _atoi - convert string to integer
 * @s: the string
 * Return: none
 */

int _atoi(char *s)
{
	int i, len, isneg, isdig, nth, dig;

	i = 0;
	len = 0;
	isneg = 0;
	isdig = 0;
	nth = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	while (i < len && isdig == 0)
	{
		if (s[i] == '-')
		{
			++isneg;
		}
		if (s[i] >= '0' && s[i] <= '9')
		{
			dig = s[i] - '0';
			if (isneg % 2)
			{
				dig = -dig;
			}
			nth = nth * 10 + dig;
			isdig = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
			{
				break;
			}
			isdig = 0;
		}
		i++;
	}
	if (isdig == 0)
	{
		return (0);
	}
	return (nth);
}
