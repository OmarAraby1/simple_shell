#include "main.h"

/**
 * _pathFinder - find the path of exe commands
 * @exe: the command argument
 * Return: the path of the command
 */

char *_pathFinder(char *exe)
{
	char *path, *path2, *path_tok, *exe_path;
	int exe_len, dir_len;
	struct stat buffer;

	path = _getenv("PATH");
	if (path)
	{
		path2 = _strdup(path);
		exe_len = _strlen(exe);
		path_tok = strtok(path2, ":");
		while (path_tok != NULL)
		{
			dir_len = _strlen(path_tok);
			exe_path = malloc(exe_len + dir_len + 2);
			_strcpy(exe_path, path_tok);
			_strcat(exe_path, "/");
			_strcat(exe_path, exe);
			_strcat(exe_path, "\0");
			if (stat(exe_path, &buffer) == 0)
			{
				free(path2);
				return (exe_path);
			}
			else
			{
				free(exe_path);
				path_tok = strtok(NULL, ":");
			}
		}
		free(path2);
		if (stat(exe, &buffer) == 0)
		{
			return (exe);
		}
		return (NULL);
	}
	return (NULL);
}
