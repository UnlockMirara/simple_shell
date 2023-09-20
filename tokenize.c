#include "main.h"
/**
 * tokenize:Splits a string into tokens and stores them in an array
 * @one_param: The string to split
 * @i: Current index in the tokens array
 * @tokens: Array to store the tokens
 * Return: 0 if successful, 1 on memory allocation failure
 */
int tokenize(char *one_param, int i, char **tokens)
{
	while (one_param != NULL)
	{
		if (str_cmp(one_param, "#") == 0)
			break;
		if (one_param[0] != '#')
			tokens[i] = malloc(str_len(one_param) + 1);
		else
		{
			one_param = strtok(NULL, " \t");
			continue;
		}
		if (tokens[i] == NULL)
			return (1);
		str_cpy(tokens[i], one_param);
		one_param = strtok(NULL, " \t");
		i++;
	}
	tokens[i] = NULL;
	return (0);
}
