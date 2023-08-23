#include "main.h"

/**
 * _myexit - handle errors and exit
 * @stok: 2d array with the promt splited
 * @buff: promt str
 * Return: int in exit success.
 */

int _myexit(char **stok, char *buff)
{
	int arg_exit = 0, len = 0, f = 0;

	if (stok[1] == NULL || (!_strcmp(stok[1], "0")))
	{
		_free(stok);
		free(buff);
		exit(0);
	}
	arg_exit = _atoi(stok[1]);
	if (arg_exit > 0 && arg_exit <= 255)
	{
		_free(stok);
		free(buff);
		exit(arg_exit);
	}
	else
	{
		len = _strlen(stok[1]);
		write(STDOUT_FILENO, "exit: Illegal number: ", 22);
		write(STDOUT_FILENO, stok[1], len);
		write(STDOUT_FILENO, "\n", 1);
		f = 2;
	}
	return (f);
}
