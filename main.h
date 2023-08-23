#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define END_OF_FILE -2
#define EXIT -3

extern char **environ;
char *name;
int hist;
/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;
/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command's function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int s_o, unsigned int s_n);
char **_strtok(char *str, char *delim);
char *_pathFind(char *com);
list_t *get_path_dir(char *path);
int _execute(char **args, char **front);
void free_list(list_t *head);
char *_itoa(int num);

void _parser2(char **str, ssize_t read);
void _parser1(char **args, int *com_ret);
ssize_t get_new_len(char *line);
char *get_pid(void);
char *get_env_value(char *beginning, int len);
char *get_args(char *str, int *com_ret);
int call_args(char **args, char **front, int *com_ret);
int run_args(char **args, char **front, int *com_ret);
int _arghand(int *com_ret);
int check_args(char **args);
void free_args(char **args, char **front);

int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strspn(char *s, char *acc);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

int (*_getbuilt(char *com))(char **args, char **front);
int _myexit(char **args, char **front);
int _myenv(char **args, char __attribute__((__unused__)) **front);
int _mysetenv(char **args, char __attribute__((__unused__)) **front);
int _myunsetenv(char **args, char __attribute__((__unused__)) **front);
int _mycd(char **args, char __attribute__((__unused__)) **front);

char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);

int _errhand(char **args, int err);
char *error_env(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
char *error_126(char **args);
char *error_127(char **args);

list_t *add_node_end(list_t **head, char *dir);
void free_list(list_t *head);

int _comproc(char *f_path, int *com_ret);
#endif /* _SHELL_H_ */
