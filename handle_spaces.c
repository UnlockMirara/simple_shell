#include "main.h"
/**
 * copy_non_space_strings - Copies non-space strings from params to argv.
 * @argv: A pointer to the destination array of strings
 * @params: A pointer to the source array of strings to process
 * @token: The first token to be included in the argv array.
 */
void copy_non_space_strings(char **argv, char **params, char *token)
{
	int argv_index = 1, i, k, j;
	int contains_only_spaces;

	argv[0] = token;
	for (i = 0; params[i] != NULL; i++)
	{
		contains_only_spaces = 1;
		for (j = 0; params[i][j]; j++)
		{
			if (params[i][j] != ' ' && params[i][j] != '\t')
			{
				contains_only_spaces = 0;
				break;
			}
		}
		if (!contains_only_spaces)
		{
			k = 0;
			argv[argv_index] = malloc(sizeof(char) * (str_len(params[i]) + 1));
			for (j = 0; params[i][j]; j++)
			{
				if (params[i][j] != ' ' && params[i][j] != '\t')
				{
					argv[argv_index][k] = params[i][j];
					k++;
				}
			}
			argv[argv_index][k] = '\0';
			argv_index++;
		}
	}
	argv[argv_index] = NULL;
}
/**
 * check_line_empty - Checks if a string consists of only whitespace characters
 * @input: The input string to be checked
 *
 * Return: 1 if the string contains only whitespace characters, 0 otherwise
 */
int check_line_empty(char *input)
{
	int empty_spaces = 1;
	int i;

	if (input[0] == '#')
		return (empty_spaces);
	for (i = 0; input[i] ; i++)
	{
		if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n')
		{
			empty_spaces = 0;
			break;
		}
	}
	return (empty_spaces);
}
