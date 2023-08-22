#include "main.h"

/**
 * _error - prints the error
 * @argv: tokenized string
 * @name: input command
 * Return: pointer to string
 */

char *_error(char **argv, char *name)
{
	char *err;
	int len;

	len = _strlen(name) + _strlen(argv[0]) + 17;
	err = malloc(sizeof(char) * (len + 1));
	if (!err)
	{
		return (NULL);
	}
	_strcpy(err, name);
	_strcat(err, ": 1: ");
	_strcat(err, argv[0]);
	_strcat(err, ": not found\n");
	return (err);
}

/**
 * _check - check if command exist
 * @argv: list of passed arguments to the prompt
 * @name: input command
 * Return: Nothing
 */

int _check(char **argv, char *name)
{
	char *exe = NULL, *fexe = NULL, *err;

	if (argv)
	{exe = argv[0];
		if (exe[0] != '/' && exe[0] != '0')
			fexe = _pathFinder(exe);
		if (!fexe || (access(fexe, F_OK) == -1))
		{err = _error(argv, name);
			write(STDERR_FILENO, err, _strlen(err));
			return (1);
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
