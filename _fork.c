#include "main.h"

/**
 * _fork - create a child process
 * @stok: tokenized input string
 * Return: 0 Success
 */

int _fork(char **stok)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
	perror("Error");
	return (EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(stok[0], stok, environ) < 0)
		{
			perror("Error");
		}
		free(stok);
		exit(127);
	}
	else
	{
		do
			waitpid(pid, &status, WUNTRACED);
		while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}
	return (EXIT_SUCCESS);
}
