#include "main.h"
/**
 * change_dir-function that changes the currenct working directory
 * @params : double pointer to the path to the new directory
 * @argv : An array of pointers to the command-line arguments
 */
void change_dir(char **params, char *argv)
{
	int i;
	char buffer[1024];

	for (i = 0; params[i] != NULL; i++)
		;
	if (i == 1)
	{
		if (chdir("/root") == -1)
			perror("");
	}
	else if (i == 2)
	{
		if (str_cmp(params[1], "-") == 0)
		{
			if (chdir("/root") == -1)
				perror(params[1]);
			return;
		}
		if (params[1][0] == '/')
		{
			if (access(params[1], F_OK) != 0)
			{
				not_existing_dir(argv, params[1]);
				return;
			}
			if (chdir(params[1]) == -1)
				perror(params[1]);
		}
		else
		{
			if (getcwd(buffer, sizeof(buffer)) != NULL)
				get_absolute_path(params[1], buffer);
			else
				perror("");
		}
	}
}

/**
 * get_absolute_path - function that returns the abs path of the user input
 * @rel_path : user input relative path
 * @cwd : current working directory
 */
void get_absolute_path(char *rel_path, char *cwd)
{
	char *new_dir;
	int i, j;

	new_dir = malloc(sizeof(char) * (str_len(cwd) + str_len(rel_path + 1)));
	for (i = 0; cwd[i] ; i++)
		new_dir[i] = cwd[i];
	new_dir[i] = '/';
	for (j = 0 ; rel_path[j] ; j++)
		new_dir[i + j + 1] = rel_path[j];
	new_dir[i + j + 1] = '\0';
	if (chdir(new_dir) == -1)
		perror(rel_path);
	free(new_dir);
}
