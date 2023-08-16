#include "main.h"

/**
 * main - My Propmt
 * @argc: number of passed arguments
 * @argv: list of passed arguments
 * Return: 0 Success
 */

int main(int argc, char **argv)
{
	char *pr = "oi $ ";
	char *lineptr;
	size_t n = 0;
	(void)argc;
	(void)argv;
	ssize_t out_gl;

	while (1)
	{
		printf("%s", pr);
		out_gl = getline(&lineptr, &n, stdin);
		if (out_gl == -1)
		{
			return (-1);
		}
		printf("%s\n", lineptr);
		free(lineptr);
	}
	return (0);
}
