#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <dirent.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;
int str_len(char *c);
void str_cpy(char *dest, const char *src);
void input_controller(char **input, char *argv);
int handle_command(char *path, char **params, char *argv);
int check_line_empty(char *input);
void free_double_pointer(char **ptr, int length);
int str_cmp(const char *x, const char *y);
char **separate_params(char *input);
void change_dir(char **params, char *argv);
void print_error(char *message, char *argv);
void not_existing_dir(char *argv, char *dir);
char *get_previous_dir(void);
int tokenize(char *one_param, int i, char **tokens);
int command_type(char *token, const char *path, char **params, char *argv);
int exit_shell(char **params, char *argv);
void get_absolute_path(char *rel_path, char *cwd);
char *get_path(char *argv);
char *token_dirs(char *penv_cp, char *argv, char *penv);
char *_strcat(char *dest, char *src);
void copy_non_space_strings(char **argv, char **params, char *token);
int string_to_int(const char *str);
char *_strtok(char *str, const char *delim);
void not_found_exec(char **args, char *argv, int j);
void not_found(char *argv, char *exec);
#endif
