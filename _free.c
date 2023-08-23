#include "main.h"

/**
 * free_args - Frees up memory taken by args
 * @args: list of input arguments
 * @front: A double pointer to the beginning of args
 */
void free_args(char **args, char **front)
{
	size_t i;

	for (i = 0; args[i] || args[i + 1]; i++)
		free(args[i]);
	free(front);
}

/**
 * free_list - Frees a list_t linked list
 * @head: The head of the list_t list
 */

void free_list(list_t *head)
{
	list_t *next;

	while (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}
