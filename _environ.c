#include "main.h"

/**
 * _getenv - Gets an environmental variable from the PATH
 * @var: The name of the environmental variable
 * Return: pointer to the env or NULL
 */

char **_getenv(const char *var)
{
	int i, len;

	len = _strlen(var);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(var, environ[i], len) == 0)
			return (&environ[i]);
	}

	return (NULL);
}

/**
 * _copyenv - Creates a copy of the environment
 * Return: double pointer or NULL
 */

char **_copyenv(void)
{
	char **env2;
	size_t len;
	int i;

	for (len = 0; environ[len]; len++)
		;
	env2 = malloc(sizeof(char *) * (len + 1));
	if (!env2)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		env2[i] = malloc(_strlen(environ[i]) + 1);
		if (!env2[i])
		{
			for (i--; i >= 0; i--)
				free(env2[i]);
			free(env2);
			return (NULL);
		}
		_strcpy(env2[i], environ[i]);
	}
	env2[i] = NULL;
	return (env2);
}

/**
 * free_env - Frees the the environment
 */
void free_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		free(environ[i]);
	free(environ);
}
