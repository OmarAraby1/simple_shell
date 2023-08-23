#include "main.h"

/**
 * sighand - action for SIGINT change
 * @sig: value for SIGINT
 */

void sighand(int sig)
{
	if (sig == SIGINT)
	write(STDOUT_FILENO, "\noi$ ", 5);
}

/**
 * main - my prompt main
 *@argc: arg count
 *@argv: list of parameters
 * Return: 0 Success
 */
int main(int argc, char **argv)
{
size_t buff_size = 0;
ssize_t out_get = 1;
char *buff;
int nwords = 0;

(void)argc, (void)argv;

	while (out_get > 0)
	{
		signal(SIGINT, sighand);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "oi$ ", 4);
		out_get = _getline(&buff, &buff_size, stdin);
		nwords = _count(buff);
		if (out_get < 0)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(buff);
			exit(EXIT_SUCCESS);
		}
		if (nwords > 0)
		{
			_check(buff, environ);
		}
	}
	free(buff);
	return (0);
}
