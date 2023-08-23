#include "main.h"

/**
 * _pathCheker - check the PATH
 * @stok: tokenized string input
 * @env: environment variable
 * Return: int flag
 */

int _pathCheker(char **stok, char *env)
{
	char **toks;
	int plen, toklen, i, f = 0;
	unsigned int s_o, s_n;
	struct stat cmd;

	toks = _tokenize(env, ":");
	plen = _strlen(stok[0]);
	i = 0;
	while (toks[i])
	{
		toklen = _strlen(toks[i]) + 2;
		s_o = _strlen(toks[i]) + 1;
		s_n = sizeof(char) * (toklen + plen);
		toks[i] = _realloc(toks[i], s_o, s_n);
		_strcat(toks[i], "/");
		_strcat(toks[i], stok[0]);
		if (stat(toks[i], &cmd) == 0)
		{
			stok[0] = _realloc(stok[0], (plen + 1), s_n);
			_strcpy(stok[0], toks[i]);
			f = 1;
			break;
		}
		i++;
	}
	_free(toks);
	return (f);
}
