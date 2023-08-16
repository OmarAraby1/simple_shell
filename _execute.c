#include "main.h"

/**
 * _execute - execute the commands
 * @argv: list of passed arguments to the prompt
 * Return: Nothing
 */

void _execute(char **argv)
{
	char *exe;

	if (argv)
	{
		exe = argv[0];
		if (execve(exe, argv, NULL) == -1)
		{
			perror("Error");
		}
	}
}
