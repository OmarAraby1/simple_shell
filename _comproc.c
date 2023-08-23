#include "main.h"

/**
 * cant_open - print can't open
 * @fpath: Path to the file
 * Return: 127.
 */

int cant_open(char *fpath)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (127);
	len = _strlen(name) + _strlen(hist_str) + _strlen(fpath) + 16;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (127);
	}
	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": Can't open ");
	_strcat(error, fpath);
	_strcat(error, "\n");
	free(hist_str);
	write(STDERR_FILENO, error, len);
	free(error);
	return (127);
}

/**
 * _comproc - runs the command of a file
 * @fpath: Path to the file
 * @com_ret: Return value of command
 * Return: 127 or -1 or com_ret
 */

int _comproc(char *fpath, int *com_ret)
{
	ssize_t f, b_read, i;
	unsigned int str_size = 0;
	unsigned int s_o = 120;
	char *str, **args, **front;
	char buff[120];
	int ret;

	hist = 0;
	f = open(fpath, O_RDONLY);
	if (f == -1)
	{*com_ret = cant_open(fpath);
		return (*com_ret);
	}
	str = malloc(sizeof(char) * s_o);
	if (!str)
		return (-1);
	do {b_read = read(f, buff, 119);
		if (b_read == 0 && str_size == 0)
			return (*com_ret);
		buff[b_read] = '\0';
		str_size += b_read;
		str = _realloc(str, s_o, str_size);
		_strcat(str, buff);
		s_o = str_size;
	} while (b_read);
	for (i = 0; str[i] == '\n'; i++)
		str[i] = ' ';
	for (; i < str_size; i++)
	{
		if (str[i] == '\n')
		{str[i] = ';';
			for (i += 1; i < str_size && str[i] == '\n'; i++)
				str[i] = ' ';
		}
	}
	_parser1(&str, com_ret);
	_parser2(&str, str_size);
	args = _strtok(str, " ");
	free(str);
	if (!args)
		return (0);
	if (check_args(args) != 0)
	{*com_ret = 2;
		free_args(args, args);
		return (*com_ret);
	}
	front = args;
	for (i = 0; args[i]; i++)
	{
		if (_strncmp(args[i], ";", 1) == 0)
		{free(args[i]);
			args[i] = NULL;
			ret = call_args(args, front, com_ret);
			args = &args[++i];
			i = 0;
		}
	}
	ret = call_args(args, front, com_ret);
	free(front);
	return (ret);
}
