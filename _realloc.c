#include "main.h"

/**
 * _realloc -reallocate new memory to a pointer
 * @ptr: pointer to reallocate
 * @old_size: old size
 * @new_size: new size
 * Return: new pointer with new size
 */
void *_realloc(void *ptr, unsigned int s_o, unsigned int s_n)
{
	char *a;
	int x, i;

	if (s_n > s_o)
		x = s_o;
	else
		x = s_n;
	if (s_n == s_o)
		return (ptr);
	if (s_n == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	a = NULL;
	a = malloc(s_n);
	if (a == NULL)
		return (NULL);
	if (ptr == NULL)
		return (a);
	for (i = 0; i < x; i++)
		a[i] = ((char *) ptr)[i];
	free(ptr);
	return (a);
}
