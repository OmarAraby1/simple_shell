#include "main.h"

/**
 * prep_exe - prepare full exe path
 * @dir_len: length of directory to allocate the path
 * @exe_len: length of command to allocate the path
 * @path_tok: the path strings
 * @exe: to concatinate to the path
 * Return: pointer to the path
 */

char *prep_exe(int dir_len, int exe_len, char *path_tok, char *exe)
{
	char *exe_p;

	exe_p = malloc(dir_len + exe_len + 2);
	if (exe_p == NULL)
	{
		perror("allocation error");
		return (NULL);
	}
	_strcpy(exe_p, path_tok);
	_strcat(exe_p, "/");
	_strcat(exe_p, exe);
	_strcat(exe_p, "\0");
	return (exe_p);
}
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

	if (stat(exe, &buff) == 0)
		return (exe);
	if (stat(exe, &buff) != 0)
	{
		path = _getenv("PATH");
		if (path)
		{
			path2 = _strdup(path);
			exe_len = _strlen(exe);
			path_tok = strtok(path2, ":");
			while (path_tok != NULL)
			{
				dir_len = _strlen(path_tok);
				exe_path = prep_exe(dir_len, exe_len, path_tok, exe);
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
		}
		free(path2);
	}
	return (NULL);
}
