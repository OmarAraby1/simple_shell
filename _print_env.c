#include "main.h"

/**
 * _print_env - print env variable
 * @env: pointer with the enviroment
 */

void _print_env(char **env)
{
	int i = 0, x;

	while (env[i])
	{
		x = 0;
		while (env[i][x])
			{
			_putchar(env[i][x]);
			x++;
			}
		if (x != 0)
			{
			_putchar('\n');
			}
		i++;
	}
}
