#include "main.h"

/**
 * get_args - Gets a command from input
 * @str: the command
 * @com_ret: return value of command.
 * Return: command or null
 */

char *get_args(char *str, int *com_ret)
{
	size_t n = 0;
	ssize_t read;
	char *pro = "oi$ ";

	if (str)
		free(str);
	read = _getline(&str, &n, STDIN_FILENO);
	if (read == -1)
		return (NULL);
	if (read == 1)
	{
		hist++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, pro, 4);
		return (get_args(str, com_ret));
	}
	str[read - 1] = '\0';
	_parser1(&str, com_ret);
	_parser2(&str, read);
	return (str);
}

/**
 * call_args - cut operations from commands to call
 * @args: An array of args
 * @front: A double pointer to the begin
 * @com_ret: return value of command
 * Return: The return value com_ret
 */

int call_args(char **args, char **front, int *com_ret)
{
	int ret, i;

	if (!args[0])
		return (*com_ret);
	for (i = 0; args[i]; i++)
	{
		if (_strncmp(args[i], "||", 2) == 0)
		{
			free(args[i]);
			args[i] = NULL;
			ret = run_args(args, front, com_ret);
			if (*com_ret != 0)
			{
				args = &args[++i];
				i = 0;
			}
			else
			{
				for (i++; args[i]; i++)
					free(args[i]);
				return (ret);
			}
		}
		else if (_strncmp(args[i], "&&", 2) == 0)
		{
			free(args[i]);
			args[i] = NULL;
			ret = run_args(args, front, com_ret);
			if (*com_ret == 0)
			{
				args = &args[++i];
				i = 0;
			}
			else
			{
				for (i++; args[i]; i++)
					free(args[i]);
				return (ret);
			}
		}
	}
	ret = run_args(args, front, com_ret);
	return (ret);
}

/**
 * run_args -execute commands
 * @args:list of inputs
 * @front: A double pointer to the beginning of args
 * @com_ret: return value of prev command
 * Return: The return value com_ret
 */

int run_args(char **args, char **front, int *com_ret)
{
	int ret, i;
	int (*builtin)(char **args, char **front);

	builtin = _getbuilt(args[0]);
	if (builtin)
	{
		ret = builtin(args + 1, front);
		if (ret != EXIT)
			*com_ret = ret;
	}
	else
	{
		*com_ret = _execute(args, front);
		ret = *com_ret;
	}
	hist++;
	for (i = 0; args[i]; i++)
		free(args[i]);
	return (ret);
}

/**
 * _arghand - handle passed argument and exectute them
 * @com_ret: return value of prev command
 * Return: -2 or -1 or com_ret
 */

int _arghand(int *com_ret)
{
	int ret = 0, i;
	char **args, *str = NULL, **front;

	str = get_args(str, com_ret);
	if (!str)
		return (END_OF_FILE);
	args = _strtok(str, " ");
	free(str);
	if (!args)
		return (ret);
	if (check_args(args) != 0)
	{
		*com_ret = 2;
		free_args(args, args);
		return (*com_ret);
	}
	front = args;
	for (i = 0; args[i]; i++)
	{
		if (_strncmp(args[i], ";", 1) == 0)
		{
			free(args[i]);
			args[i] = NULL;
			ret = call_args(args, front, com_ret);
			args = &args[++i];
			i = 0;
		}
	}
	if (args)
		ret = call_args(args, front, com_ret);
	free(front);
	return (ret);
}

/**
 * check_args - check seperators and new lines
 * @args: tokenized passed command string
 * Return: -2 or 0
 */

int check_args(char **args)
{
	size_t i;
	char *cur, *nex;

	for (i = 0; args[i]; i++)
	{
		cur = args[i];
		if (cur[0] == ';' || cur[0] == '&' || cur[0] == '|')
		{
			if (i == 0 || cur[1] == ';')
				return (_errhand(&args[i], 2));
			nex = args[i + 1];
			if (nex && (nex[0] == ';' || nex[0] == '&' || nex[0] == '|'))
				return (_errhand(&args[i + 1], 2));
		}
	}
	return (0);
}
