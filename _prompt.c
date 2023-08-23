#include "main.h"

/**
 * sighand - Prints a new prompt upon a signal
 * @sig: The signal
 */

void sighand(int sig)
{
	char *pro = "\noi$ ";

	(void)sig;
	signal(SIGINT, sighand);
	write(STDIN_FILENO, pro, 5);
}

/**
 * main - simple shell entrance
 * @argc: The number of arguments
 * @argv: array of pointers to the arguments
 * Return: value of last executed
 */

int main(int argc, char *argv[])
{
	int ret = 0, retn, *com_ret = &retn;
	char *pro = "oi$ ", *nl = "\n";

	name = argv[0];
	hist = 1;
	signal(SIGINT, sighand);
	*com_ret = 0;
	environ = _copyenv();
	if (!environ)
		exit(-100);
	if (argc != 1)
	{
		ret = _comproc(argv[1], com_ret);
		free_env();
		return (*com_ret);
	}
	if (!isatty(STDIN_FILENO))
	{
		while (ret != END_OF_FILE && ret != EXIT)
			ret = _arghand(com_ret);
		free_env();
		return (*com_ret);
	}
	while (1)
	{
		write(STDOUT_FILENO, pro, 4);
		ret = _arghand(com_ret);
		if (ret == END_OF_FILE || ret == EXIT)
		{
			if (ret == END_OF_FILE)
				write(STDOUT_FILENO, nl, 1);
			free_env();
			exit(*com_ret);
		}
	}

	free_env();
	return (*com_ret);
}
