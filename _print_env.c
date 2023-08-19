#include "main.h"

/**
 * _print_env - print environment variable
 * Return: Nothing
 */

void _print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
