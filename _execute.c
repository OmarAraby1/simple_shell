#include "main.h"

/**
 * _execute - Executes a command in a child process
 * @args: An array of arguments
 * @front: A double pointer to the beginning of args
 * Return: err number if there is
 */

int _execute(char **args, char **front)
{
	pid_t child_pid;
	int status, f = 0, ret = 0;
	char *com = args[0];

	if (com[0] != '/' && com[0] != '.')
	{
		f = 1;
		com = _pathFind(com);
	}

	if (!com || (access(com, F_OK) == -1))
	{
		if (errno == EACCES)
			ret = (_errhand(args, 126));
		else
			ret = (_errhand(args, 127));
	}
	else
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			if (f)
				free(com);
			perror("Error child:");
			return (1);
		}
		if (child_pid == 0)
		{
			execve(com, args, environ);
			if (errno == EACCES)
				ret = (_errhand(args, 126));
			free_env();
			free_args(args, front);
			_exit(ret);
		}
		else
		{
			wait(&status);
			ret = WEXITSTATUS(status);
		}
	}
	if (f)
		free(com);
	return (ret);
}
