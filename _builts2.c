#include "main.h"

/**
 * _myenv - Prints the current environment
 * @args: passed arguments
 * @front: A double pointer to the beginning of args
 * Return: -1 or 0
 */

int _myenv(char **args, char __attribute__((__unused__)) **front)
{
	int i;
	char nc = '\n';

	if (!environ)
		return (-1);
	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, &nc, 1);
	}
	(void)args;
	return (0);
}

/**
 * _mysetenv - Changes or adds an environmental variable to the PATH
 * @args: passed arguments
 * @front: A double pointer to the beginning of args
 * Return: -1 or 0
 */

int _mysetenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_var = NULL, **new_env, *new_val;
	size_t len;
	int i;

	if (!args[0] || !args[1])
		return (_errhand(args, -1));

	new_val = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!new_val)
		return (_errhand(args, -1));
	_strcpy(new_val, args[0]);
	_strcat(new_val, "=");
	_strcat(new_val, args[1]);

	env_var = _getenv(args[0]);
	if (env_var)
	{
		free(*env_var);
		*env_var = new_val;
		return (0);
	}
	for (len = 0; environ[len]; len++)
		;

	new_env = malloc(sizeof(char *) * (len + 2));
	if (!new_env)
	{
		free(new_val);
		return (_errhand(args, -1));
	}
	for (i = 0; environ[i]; i++)
		new_env[i] = environ[i];
	free(environ);
	environ = new_env;
	environ[i] = new_val;
	environ[i + 1] = NULL;
	return (0);
}

/**
 * _myunsetenv - Deletes an environmental variable
 * @args: passed arguments.
 * @front: A double pointer to the beginning of args
 * Return: -1 or 0
 */

int _myunsetenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_var, **new_env;
	size_t len;
	int i, j;

	if (!args[0])
		return (_errhand(args, -1));
	env_var = _getenv(args[0]);
	if (!env_var)
		return (0);
	for (len = 0; environ[len]; len++)
		;
	new_env = malloc(sizeof(char *) * len);
	if (!new_env)
		return (_errhand(args, -1));
	for (i = 0, j = 0; environ[i]; i++)
	{
		if (*env_var == environ[i])
		{
			free(*env_var);
			continue;
		}
		new_env[j] = environ[i];
		j++;
	}
	free(environ);
	environ = new_env;
	environ[len - 1] = NULL;
	return (0);
}
