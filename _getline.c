#include "main.h"

/**
 * _realloc - Reallocates a memory block
 * @ptr: A pointer to memory
 * @s_o: old size
 * @s_n: new size
 * Return: ptr or pointer to reallocated ot 0 or NULL
 */

void *_realloc(void *ptr, unsigned int s_o, unsigned int s_n)
{
	void *mem;
	char *ptr_copy, *filler;
	unsigned int i;

	if (s_n == s_o)
		return (ptr);
	if (ptr == NULL)
	{
		mem = malloc(s_n);
		if (mem == NULL)
			return (NULL);
		return (mem);
	}
	if (s_n == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	ptr_copy = ptr;
	mem = malloc(sizeof(*ptr_copy) * s_n);
	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}
	filler = mem;
	for (i = 0; i < s_o && i < s_n; i++)
		filler[i] = *ptr_copy++;
	free(ptr);
	return (mem);
}

/**
 * assign_lineptr - Reassigns the lineptr variable for _getline.
 * @lineptr: A buffer to store an input string
 * @n: The size of lineptr
 * @buff: The string to assign to lineptr
 * @b: The size of buffer
 */

void assign_lineptr(char **lineptr, size_t *n, char *buff, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buff;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buff;
	}
	else
	{
		_strcpy(*lineptr, buff);
		free(buff);
	}
}

/**
 * _getline - Reads input from a stream
 * @lineptr: A buffer to store the input
 * @n: The size of lineptr
 * @stream: The stream to read from
 * Return: The number of bytes read
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t inp;
	ssize_t ret;
	char c = 'x', *buff;
	int r;

	if (inp == 0)
		fflush(stream);
	else
		return (-1);
	inp = 0;
	buff = malloc(sizeof(char) * 120);
	if (!buff)
		return (-1);
	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && inp == 0))
		{
			free(buff);
			return (-1);
		}
		if (r == 0 && inp != 0)
		{
			inp++;
			break;
		}
		if (inp >= 120)
			buff = _realloc(buff, inp, inp + 1);
		buff[inp] = c;
		inp++;
	}
	buff[inp] = '\0';
	assign_lineptr(lineptr, n, buff, inp);
	ret = inp;
	if (r != 0)
		inp = 0;
	return (ret);
}
