#include "main.h"

/**
 * get_builtin - Matches a command with a corresponding builtin
 * @com: The command to match
 * Return: A function pointer to the corresponding builtin
 */

int (*_getbuilt(char *com))(char **args, char **front)
{
	builtin_t funcs[] = {
		{ "exit", _myexit },
		{ "env", _myenv },
		{ "setenv", _mysetenv },
		{ "unsetenv", _myunsetenv },
		{ "cd", _mycd },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; funcs[i].name; i++)
	{
		if (_strcmp(funcs[i].name, com) == 0)
			break;
	}
	return (funcs[i].f);
}

/**
 * __myexit - Causes normal process termination
 * @args: exit values input
 * @front: A double pointer to the beginning of args
 * Return: -3 or -2 or 0
 */

int _myexit(char **args, char **front)
{
	int i, len_of_int = 10;
	unsigned int num = 0, max = 1 << (sizeof(int) * 8 - 1);

	if (args[0])
	{
		if (args[0][0] == '+')
		{
			i = 1;
			len_of_int++;
		}
		for (; args[0][i]; i++)
		{
			if (i <= len_of_int && args[0][i] >= '0' && args[0][i] <= '9')
				num = (num * 10) + (args[0][i] - '0');
			else
				return (_errhand(--args, 2));
		}
	}
	else
	{
		return (-3);
	}
	if (num > max - 1)
		return (_errhand(--args, 2));
	args -= 1;
	free_args(args, front);
	free_env();
	exit(num);
}

/**
 * _mycd - Changes the current directory
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 * Return: -2 or -1 or 0
 */

int _mycd(char **args, char __attribute__((__unused__)) **front)
{
	char **dir_info, *nl = "\n";
	char *oldpwd = NULL, *pwd = NULL;
	struct stat dir;

	oldpwd = getcwd(oldpwd, 0);
	if (!oldpwd)
		return (-1);

	if (args[0])
	{
		if (*(args[0]) == '-' || _strcmp(args[0], "--") == 0)
		{
			if ((args[0][1] == '-' && args[0][2] == '\0') ||
					args[0][1] == '\0')
			{
				if (_getenv("OLDPWD") != NULL)
					(chdir(*_getenv("OLDPWD") + 7));
			}
			else
			{
				free(oldpwd);
				return (_errhand(args, 2));
			}
		}
		else
		{
			if (stat(args[0], &dir) == 0 && S_ISDIR(dir.st_mode)
					&& ((dir.st_mode & S_IXUSR) != 0))
				chdir(args[0]);
			else
			{
				free(oldpwd);
				return (_errhand(args, 2));
			}
		}
	}
	else
	{
		if (_getenv("HOME") != NULL)
			chdir(*(_getenv("HOME")) + 5);
	}

	pwd = getcwd(pwd, 0);
	if (!pwd)
		return (-1);

	dir_info = malloc(sizeof(char *) * 2);
	if (!dir_info)
		return (-1);

	dir_info[0] = "OLDPWD";
	dir_info[1] = oldpwd;
	if (_mysetenv(dir_info, dir_info) == -1)
		return (-1);

	dir_info[0] = "PWD";
	dir_info[1] = pwd;
	if (_mysetenv(dir_info, dir_info) == -1)
		return (-1);
	if (args[0] && args[0][0] == '-' && args[0][1] != '-')
	{
		write(STDOUT_FILENO, pwd, _strlen(pwd));
		write(STDOUT_FILENO, nl, 1);
	}
	free(oldpwd);
	free(pwd);
	free(dir_info);
	return (0);
}
