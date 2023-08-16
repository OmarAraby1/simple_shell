#include "main.h"

/**
 * _execute - execute the commands
 * @argv: list of passed arguments to the prompt
 * Return: Nothing
 */

void _execute(char **argv)
{
	char *exe = NULL;
	char *fexe = NULL;

	if (argv)
	{
		exe = argv[0];
		fexe = _pathFinder(exe);
		if (execve(fexe, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
