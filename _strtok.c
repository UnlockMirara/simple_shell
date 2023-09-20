#include "main.h"
/**
 * _strtok - function that tokenizes a string based on given delimiters.
 * @str: input string to tokenize.
 * @delim: string containing delimiters.
 *
 * Return: char * or NULL
 */

char *_strtok(char *str, const char *delim)
{
	static char *last;
	char *token = NULL, *pos = NULL;
	char checkDelim;

	if (str != NULL)
		token = str;
	else if (last != NULL)
		token = last;
	else
		return (NULL);
	pos = token;
	while (*pos != '\0')
	{
		const char *c = delim;

		checkDelim = 0;
		while (*c != '\0')
		{
			if (*pos == *c)
			{
				checkDelim = 1;
				break;
			}
			c++;
		}
		if (checkDelim)
		{
			*pos = '\0';
			last = pos + 1;
			return (token);
		}
		pos++;
	}
	last = NULL;
	return (token);
}
