#include "main.h"
/**
 * str_len - returns the lenght of string
 * @c: pointer
 * Return: return length
 */

int str_len(char *c)
{
	int i;

	for (i = 0 ; *c != '\0'; c++)
		++i;
	return (i);
}

/**
 * str_cmp - it compares if two strings
 * @x: first string
 * @y: second string
 * Return: <0: (x  < y), > 0:(x == y) and >0:(x > y)
 */
int str_cmp(const char *x, const char *y)
{
	while (*x == *y)
	{
		if (*x == '\0')
		return (0);
		 x++;
		 y++;
	}
	if (*x > *y)
		return (*x - *y);
	else
		return (*y - *x);
}
/**
 * str_cpy - function that copies a string from source to destination
 * @x: destination string
 * @y: source string
 * Return: <0: (x  < y), > 0:(x == y) and >0:(x > y)
 */
void str_cpy(char *x, const char *y)
{
	while (*y != '\0')
	{
		*x = *y;
		x++;
		y++;
	}
	*x = '\0';
}


/**
 * _strcat - concatenates two strings
 * @dest: firts string
 * @src: second string
 * Return: first string
 */
char *_strcat(char *dest, char *src)
{
	int x = 0;
	int y = 0;

	while (dest[x])
		x++;
	for (y = 0; src[y]; y++)
		dest[x++] = src[y];
	dest[x] = '\0';
	return (dest);
}
