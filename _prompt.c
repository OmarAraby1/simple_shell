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
	char **argv, *tok;
	int n_tok = 0, i;

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
		if (argv == NULL)
		{
			free(lineptr2);
			free(argv);
			perror("memory allocation error");
			return (NULL);
		}
		_strcpy(argv[i], tok);
		tok = strtok(NULL, dilem);
	}
	argv[i] = NULL;
	free(lineptr2);
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
	char *pr = "oi$ ", *lineptr, *lineptr2;
	const char *dilem = " \n";
	size_t n = 0;
	pid_t pid;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, pr, 4);
		out_gl = getline(&lineptr, &n, stdin);
		if (out_gl == -1)
			break;
		if (_strcmp(lineptr, "exit\n") == 0)
			break;
		if (_strcmp(lineptr, "env\n") == 0)
		{
			_print_env();
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			lineptr2 = malloc(sizeof(char) * out_gl);
			if (lineptr2 == NULL)
			{
				perror("memory allocation error");
				return (-1);
			}
			_strcpy(lineptr2, lineptr);
			argv = _tokenize(lineptr, lineptr2, dilem);
			_execute(argv);
			exit(0);
		}
		else if (pid > 0)
			wait(NULL);

		else
		{
			perror("fork error");
			exit(1);
		}
	}
	free(lineptr);
	return (0);
}
