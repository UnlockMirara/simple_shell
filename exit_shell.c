#include "main.h"
/**
 * exit_shell - Terminate the shell or exit a process with a status code.
 * @params: Double pointer to an array of command parameters.
 * @argv: Pointer to the executable's name
 * Return: int
 */
int exit_shell(char **params, char *argv)
{
	int i;
	int status;

	for (i = 0; params[i] != NULL; i++)
		;
	if (i == 0)
		return (0);
	if (i > 1)
	{
		perror("error");
		return (0);
	}
	if (i == 1)
	{
		status = string_to_int(params[0]);
		if (status < 0)
		{
			print_error("1: exit: Illegal number: ", argv);
			write(STDERR_FILENO, params[0], str_len(params[0]));
			write(STDERR_FILENO, "\n", 1);
			return (2);
		}
		else
			return (status);
	}
	return (0);
}
/**
 * string_to_int - Convert a string to an integer.
 * @str: Pointer to the input null-terminated character array.
 * Return: On successful conversion, returns the corresponding integer value.
 * If the input string is not a valid integer representation, returns -1.
 */
int string_to_int(const char *str)
{
	int result = 0;
	int isNegative = 0;

	if (*str == '-')
	{
		isNegative = 1;
		str++;
	}

	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			result = result * 10 + (*str - '0');
			str++;
		}
		else
			return (-1);
	}

	if (isNegative)
		result = -result;
	return (result);
}


