#include "main.h"

/**
 * _print_env - print environment variable
 * Return: Nothing
 */

void _print_env(void)
{
	char **env = environ;
	char nl = '\n';

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, &nl, 1);
		env++;
	}
}
