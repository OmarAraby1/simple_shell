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
	struct stat buff;

	path = getenv("PATH");
	if (path)
	{
		path2 = malloc(sizeof(char) * strlen(path));
		if (path2 == NULL)
		{
			perror("memory allocation error");
			return (-1)
		}
		strcpy(path2, path);
		exe_len = strlen(exe);
		path_tok = strtok(path2, ":");
		while (path_tok != 0)
		{
			dir_len = strlen(path_tok);
			exe_path = malloc(exe_len + dir_len + 2);
			strcpy(exe_path, path_tok);
			strcat(exe_path, "/");
			strcat(exe_path, exe);
			strcat(exe_path, "\0");
			if (stat(exe_path, &buff) == 0)
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
		if (stat(exe, &buff) == 0)
		{
			return (exe);
		}
		return (NULL);
	}
	return (NULL);
}
