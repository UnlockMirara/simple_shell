#include "main.h"
#include <string.h>
#include <errno.h>
/**
* command_type - process the command type
* @token: command symbole
* @path : pointer to full path of the command executable
* @params: an array
* @argv: The name of the program (argv[0]).
* Return: int
*/
int command_type(char *token, const char *path, char **params, char *argv)
{
	int i, j;
	pid_t pid = fork();
	char **env = environ, **args;

	if (pid == -1)
	{
		perror("fork error");
		return (1);
	}
	for (i = 0; params[i] ; i++)
		;
	if (pid == 0)
	{
		args = malloc(sizeof(char *) * (i + 2));
		copy_non_space_strings(args, params, token);
		for (j = 0; args[j]; j++)
			;
		if (str_cmp(token, "echo") == 0 && args[1][0] == '#')
			return (0);
		not_found_exec(args, argv, j);
		execve(path, args, env);
		free_double_pointer(args, j);
		exit(1);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);

			if (exit_status == 127)
				return (127);
		}
	}
	return (0);
}
/**
 * not_found_exec - Check if files in 'args' array are not found.
 * @args: An array of strings representing command-line arguments.
 * @argv: The name of the program (argv[0]).
 * @j: The number of elements in the 'args' array.
 */
void not_found_exec(char **args, char *argv, int j)
{
	int i;

	for (i = 1; args[i]; i++)
	{
		if (args[i][0] != '-' && access(args[i], F_OK) == -1)
		{
			not_found(argv, args[i]);
			free_double_pointer(args, j);
			exit(127);
		}
	}
}
