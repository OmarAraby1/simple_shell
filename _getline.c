#include "main.h"

/**
 * assign_lineptr - Reassigns the lineptr variable for _getline.
 * @lineptr: A buffer to store an input string.
 * @n: The size of lineptr.
 * @buffer: The string to assign to lineptr.
 * @b: The size of buffer.
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * _getline - Reads input from a stream.
 * @lineptr: A buffer to store the input
 * @n: The size of lineptr
 * @stream: The stream to read from.
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
			input++;
			break;
		}
		if (input >= 120)
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
