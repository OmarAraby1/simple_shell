#include "main.h"

/**
 * get_pid - get the process ID
 * Return: The process ID or NULL
 */

char *get_pid(void)
{
	size_t i = 0;
	char *buff;
	ssize_t f;

	f = open("/proc/self/stat", O_RDONLY);
	if (f == -1)
	{
		perror("Cant read file");
		return (NULL);
	}
	buff = malloc(120);
	if (!buff)
	{
		close(f);
		return (NULL);
	}
	read(f, buff, 120);
	while (buff[i] != ' ')
		i++;
	buff[i] = '\0';
	close(f);
	return (buff);
}

/**
 * logical_ops - Checks a line for logical operators "||" or "&&"
 * @str: pointer to string to check
 * @new_len: Pointer to new_len in get_new_len
 */

void logical_ops(char *str, ssize_t *new_len)
{
	char prev, curr, nex;

	prev = *(str - 1);
	curr = *str;
	nex = *(str + 1);

	if (curr == '&')
	{
		if (nex == '&' && prev != ' ')
			(*new_len)++;
		else if (prev == '&' && nex != ' ')
			(*new_len)++;
	}
	else if (curr == '|')
	{
		if (nex == '|' && prev != ' ')
			(*new_len)++;
		else if (prev == '|' && nex != ' ')
			(*new_len)++;
	}
}

/**
 * get_env_value - Gets the value corresponding to an environmental variable.
 * @env: The env variable
 * @len: The length of the env variable
 * Return: value of environment variable or empty string
 */

char *get_env_value(char *env, int len)
{
	char **var_addr;
	char *rep = NULL, *temp, *var;

	var = malloc(len + 1);
	if (!var)
		return (NULL);
	var[0] = '\0';
	_strncat(var, env, len);
	var_addr = _getenv(var);
	free(var);
	if (var_addr)
	{
		temp = *var_addr;
		while (*temp != '=')
			temp++;
		temp++;
		rep = malloc(_strlen(temp) + 1);
		if (rep)
			_strcpy(rep, temp);
	}
	return (rep);
}

/**
 * get_new_len - Gets the new length of the parsed string
 * @str: The string to check.
 * Return: The new length of string
 */

ssize_t get_new_len(char *str)
{
	size_t i;
	ssize_t new_len = 0;
	char curr, nex;

	for (i = 0; str[i]; i++)
	{
		curr = str[i];
		nex = str[i + 1];
		if (curr == '#')
		{
			if (i == 0 || str[i - 1] == ' ')
			{
				str[i] = '\0';
				break;
			}
		}
		else if (i != 0)
		{
			if (curr == ';')
			{
				if (nex == ';' && str[i - 1] != ' ' && str[i - 1] != ';')
				{
					new_len += 2;
					continue;
				}
				else if (str[i - 1] == ';' && nex != ' ')
				{
					new_len += 2;
					continue;
				}
				if (str[i - 1] != ' ')
					new_len++;
				if (nex != ' ')
					new_len++;
			}
			else
				logical_ops(&str[i], &new_len);
		}
		else if (curr == ';')
		{
			if (i != 0 && str[i - 1] != ' ')
				new_len++;
			if (nex != ' ' && nex != ';')
				new_len++;
		}
		new_len++;
	}
	return (new_len);
}
