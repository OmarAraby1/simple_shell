#include "main.h"

/**
 * _getenv - get environment from the PATH
 * @var: The name of the environment
 * Return: pointer to the environment
 */

char *_getenv(char *var)
{
	int i, len;

	len = _strlen(var);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(var, environ[i], len) == 0)
		{
			return (environ[i]);
		}
	}
	return (NULL);
}
