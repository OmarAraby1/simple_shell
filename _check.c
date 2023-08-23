#include "main.h"

/**
 * _check - check command input
 * @buff: read line by getline
 * @envir: environment variable
 */
void _check(char  *buff, char **envir)
{
	int f = 0;
	struct stat cmd;
	char **stok = NULL, *env;

	env = _getenv("PATH");
	stok = _tokenize(buff, " \t");

	if (!(_strcmp(stok[0], "exit")))
		f = _myexit(stok, buff);
	else if (stok[0] == NULL)
		perror("./nautilus");
	else if (!(_strcmp(stok[0], "env")))
		_print_env(envir);
	if (stat(stok[0], &cmd) == 0)
		f = 1;
	else if (_strcmp(stok[0], "env") != 0)
		f = _pathCheker(stok, env);
	if (f == 1 && _strcmp(stok[0], "env") != 0)
		_fork(stok);
	else if (_strcmp(stok[0], "env") != 0)
		perror("./nautilus");
	_free(stok);
}
