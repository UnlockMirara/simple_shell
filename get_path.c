#include "main.h"

/**
 * get_path - function that searches for the executable path of a command
 * @argv: The command to search for.
 *
 * Return: The path to the executable, or NULL if not found.
 */

char *get_path(char *argv)
{
	int j, i;
	char **env = environ;
	char *exe_path = NULL, first_token[6];
	char *penv, *penv_cp;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < 5; j++)
			first_token[j] = env[i][j];
		first_token[j] = '\0';
		if (str_cmp(first_token, "PATH=") == 0)
		{
			penv = malloc(sizeof(char) * (str_len(env[i]) - 4));
			penv_cp = malloc(sizeof(char) * (str_len(env[i]) - 4));
			if (penv_cp == NULL)
			{
				free(penv);
				return (NULL);
			}
			if (penv == NULL)
			{
				free(penv_cp);
				return (NULL);
			}
			str_cpy(penv, env[i] + 5);
			str_cpy(penv_cp, penv);
			exe_path = token_dirs(penv_cp, argv, penv);
			return (exe_path);
		}
	}
	return (NULL);
}
/**
 * token_dirs -function that tokenizes & searches directories for an executable
 * @penv_cp: Copy of the PATH environment variable.
 * @argv: The command to search for.
 * @penv: The original PATH environment variable.
 *
 * Return: The path to the executable, or NULL if not found.
 */
char *token_dirs(char *penv_cp, char *argv, char *penv)
{
	char *exe_path = NULL, *path_dir;

	path_dir = strtok(penv_cp, ":;");
	while (path_dir != NULL)
	{
		exe_path = malloc(str_len(path_dir) + str_len(argv) + 2);
		if (exe_path == NULL)
		{
			free(penv);
			free(penv_cp);
			return (NULL);
		}
		str_cpy(exe_path, path_dir);
		_strcat(exe_path, "/");
		_strcat(exe_path, argv);
		if (access(exe_path, F_OK | X_OK) == 0)
		{
			free(penv);
			free(penv_cp);
			return (exe_path);
		}
		free(exe_path);
		path_dir = strtok(NULL, ":;");
	}
	free(penv);
	free(penv_cp);
	free(exe_path);
	return (NULL);
}
