#include "main.h"

/**
 * _pathFind - Locates a command in the PATH
 * @com: The command to locate
 * Return:full path or null
 */

char *_pathFind(char *com)
{
	char **path, *temp;
	list_t *dirs, *head;
	struct stat st;

	path = _getenv("PATH");
	if (!path || !(*path))
		return (NULL);
	dirs = get_path_dir(*path + 5);
	head = dirs;
	while (dirs)
	{
		temp = malloc(_strlen(dirs->dir) + _strlen(com) + 2);
		if (!temp)
			return (NULL);
		_strcpy(temp, dirs->dir);
		_strcat(temp, "/");
		_strcat(temp, com);
		if (stat(temp, &st) == 0)
		{
			free_list(head);
			return (temp);
		}
		dirs = dirs->next;
		free(temp);
	}
	free_list(head);
	return (NULL);
}

/**
 * fill_path_dir - Copies path and replace /
 * @path: The colon-separated list of directories
 * Return: copy of path without /
 */

char *fill_path_dir(char *path)
{
	int i, len = 0;
	char *path_copy, *pwd;

	pwd = *(_getenv("PWD")) + 4;
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (path[i + 1] == ':' || i == 0 || path[i + 1] == '\0')
				len += _strlen(pwd) + 1;
			else
				len++;
		}
		else
			len++;
	}
	path_copy = malloc(sizeof(char) * (len + 1));
	if (!path_copy)
		return (NULL);
	path_copy[0] = '\0';
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (i == 0)
			{
				_strcat(path_copy, pwd);
				_strcat(path_copy, ":");
			}
			else if (path[i + 1] == ':' || path[i + 1] == '\0')
			{
				_strcat(path_copy, ":");
				_strcat(path_copy, pwd);
			}
			else
				_strcat(path_copy, ":");
		}
		else
		{
			_strncat(path_copy, &path[i], 1);
		}
	}
	return (path_copy);
}

/**
 * get_path_dir - Tokenizes a the path into linked list
 * @path: The colon-separated list of directories
 * Return: A pointer to the initialized linked list
 */

list_t *get_path_dir(char *path)
{
	int i;
	char **dirs, *path_copy;
	list_t *head = NULL;

	path_copy = fill_path_dir(path);
	if (!path_copy)
		return (NULL);
	dirs = _strtok(path_copy, ":");
	free(path_copy);
	if (!dirs)
		return (NULL);
	for (i = 0; dirs[i]; i++)
	{
		if (add_node_end(&head, dirs[i]) == NULL)
		{
			free_list(head);
			free(dirs);
			return (NULL);
		}
	}
	free(dirs);
	return (head);
}

/**
 * add_node_end - Adds a node to the end oflinked list
 * @head: A pointer to the head of the list_t list
 * @dir: The directory path for the new node to contais
 * Return: NULL or pointer to new node
 */

list_t *add_node_end(list_t **head, char *dir)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *last;

	if (!new_node)
		return (NULL);
	new_node->dir = dir;
	new_node->next = NULL;
	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}
