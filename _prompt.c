#include "main.h"
/**
 * _tokenize - turn a string to tokens
 * @lineptr: the string input
 * @lineptr2: copy of lineptr
 * @dilem: the delimeter
 * Return: list of tokens
 */

char **_tokenize(char *lineptr, char *lineptr2, const char *dilem)
{
	char **argv;
	char *tok;
	int n_tok = 0;
	int i;

	tok = strtok(lineptr, dilem);
	while (tok != NULL)
	{
		n_tok++;
		tok = strtok(NULL, dilem);
	}
	n_tok++;
	argv = malloc(sizeof(char *) * n_tok);
	tok = strtok(lineptr2, dilem);
	for (i = 0; tok != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(tok));
		_strcpy(argv[i], tok);
		tok = strtok(NULL, dilem);
	}
	argv[i] = '\0';
	return (argv);
}

/**
 * main - My Propmt
 * @argc: number of passed arguments
 * @argv: list of passed arguments
 * Return: 0 Success
 */

int main(int argc, char **argv)
{
	ssize_t out_gl;
	char *pr = "oi $ ";
	char *lineptr;
	char *lineptr2;
	const char *dilem = " \n";
	size_t n = 0;
	(void)argc;

	while (1)
	{
		printf("%s", pr);
		out_gl = getline(&lineptr, &n, stdin);
		if (out_gl == -1)
		{
			return (-1);
		}
		lineptr2 = malloc(sizeof(char) * out_gl);
		if (lineptr2 == NULL)
		{
			perror("memory allocation error");
			return (-1);
		}
		_strcpy(lineptr2, lineptr);
		argv = _tokenize(lineptr, lineptr2, dilem);
		_execute(argv);
	}
	free(lineptr);
	free(lineptr2);
	return (0);
}
