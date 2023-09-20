#include "main.h"

/**
 * main - starting point of the program
 * @argc: number of command-line arguments
 * @argv: an array of pointers to the command-line arguments.
 * Return: 0  on Success
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	ssize_t gerror = 0;
	size_t size = 0;

	(void)argc;

	while (1)
	{
		line = NULL;
		gerror = getline(&line, &size, stdin);
		if (gerror == -1)
		{
			free(line);
			exit(0);
		}
		input_controller(&line, argv[0]);
		free(line);
	}
	return (0);
}

