#include "main.h"
/**
 * print_error - Prints an error message to the screen
 * @message: The error message to display
 * @argv: The name of the program or command that caused the error
 */
void print_error(char *message, char *argv)
{
	write(STDERR_FILENO, argv, str_len(argv));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, message, str_len(message));
}
/**
 * not_existing_dir - Displays an error message when trying to
 *                    access a directory that doesn't exist.
 * @argv: The command name responsible for the error.
 * @dir: The name of the nonexistent directory.
 */
void not_existing_dir(char *argv, char *dir)
{
	print_error("1: cd: can't cd to ", argv);
	write(STDERR_FILENO, dir, str_len(dir));
	write(STDERR_FILENO, "\n", 1);
}
/**
 * not_found- Displays an error when an executable isn't found
 * @argv: The command name responsible for the error
 * @exec: The nonexistent executable's name
 */
void not_found(char *argv, char *exec)
{
	print_error("1: ", argv);
	write(STDERR_FILENO, exec, str_len(exec));
	write(STDERR_FILENO, ": not found\n", 12);
}
