#include "main.h"

/**
 * _parser1 - Handles variable replacement
 * @str: A double pointer to the command
 * @com_ret: return of last command
 * Description: Replaces $$ , $?, and environ
 */

void _parser1(char **str, int *com_ret)
{
	int j, k = 0, len;
	char *rep = NULL, *old_str = NULL, *new_str;

	old_str = *str;
	for (j = 0; old_str[j]; j++)
	{
		if (old_str[j] == '$' && old_str[j + 1] &&
				old_str[j + 1] != ' ')
		{
			if (old_str[j + 1] == '$')
			{
				rep = get_pid();
				k = j + 2;
			}
			else if (old_str[j + 1] == '?')
			{
				rep = _itoa(*com_ret);
				k = j + 2;
			}
			else if (old_str[j + 1])
			{
				for (k = j + 1; old_str[k] &&
						old_str[k] != '$' &&
						old_str[k] != ' '; k++)
					;
				len = k - (j + 1);
				rep = get_env_value(&old_str[j + 1], len);
			}
			new_str = malloc(j + _strlen(rep)
					  + _strlen(&old_str[k]) + 1);
			if (!str)
				return;
			new_str[0] = '\0';
			_strncat(new_str, old_str, j);
			if (rep)
			{
				_strcat(new_str, rep);
				free(rep);
				rep = NULL;
			}
			_strcat(new_str, &old_str[k]);
			free(old_str);
			*str = new_str;
			old_str = new_str;
			j = -1;
		}
	}
}

/**
 * _parser2 - cut strings from input
 * @str: A pointer to the string read
 * @read: The length of the string
 */

void _parser2(char **str, ssize_t read)
{
	char *old_str, *new_str;
	char prev, curr, nex;
	size_t i, j;
	ssize_t new_len;

	new_len = get_new_len(*str);
	if (new_len == read - 1)
		return;
	new_str = malloc(new_len + 1);
	if (!new_str)
		return;
	j = 0;
	old_str = *str;
	for (i = 0; old_str[i]; i++)
	{
		curr = old_str[i];
		nex = old_str[i + 1];
		if (i != 0)
		{
			prev = old_str[i - 1];
			if (curr == ';')
			{
				if (nex == ';' && prev != ' ' && prev != ';')
				{
					new_str[j++] = ' ';
					new_str[j++] = ';';
					continue;
				}
				else if (prev == ';' && nex != ' ')
				{
					new_str[j++] = ';';
					new_str[j++] = ' ';
					continue;
				}
				if (prev != ' ')
					new_str[j++] = ' ';
				new_str[j++] = ';';
				if (nex != ' ')
					new_str[j++] = ' ';
				continue;
			}
			else if (curr == '&')
			{
				if (nex == '&' && prev != ' ')
					new_str[j++] = ' ';
				else if (prev == '&' && nex != ' ')
				{
					new_str[j++] = '&';
					new_str[j++] = ' ';
					continue;
				}
			}
			else if (curr == '|')
			{
				if (nex == '|' && prev != ' ')
					new_str[j++]  = ' ';
				else if (prev == '|' && nex != ' ')
				{
					new_str[j++] = '|';
					new_str[j++] = ' ';
					continue;
				}
			}
		}
		else if (curr == ';')
		{
			if (i != 0 && old_str[i - 1] != ' ')
				new_str[j++] = ' ';
			new_str[j++] = ';';
			if (nex != ' ' && nex != ';')
				new_str[j++] = ' ';
			continue;
		}
		new_str[j++] = old_str[i];
	}
	new_str[j] = '\0';

	free(*str);
	*str = new_str;
}
