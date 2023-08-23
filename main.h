#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>

#define END_OF_FILE -2
#define EXIT -3

extern char **environ;

int main(int argc, char **argv);
void sighand(int sig);
char **_tokenize(char *str, char *delim);
void _check(char *buff, char **envir);
int _myexit(char **stok, char *buff);
void _free(char **pp);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _pathCheker(char **stok, char *env);
char *_strtok(char *str, char *delim);
int _fork(char **stok);
char *_getenv(char *var);
void _print_env(char **env);

int _atoi(char *s);
size_t _count(char *s);
void *_realloc(void *ptr, unsigned int s_o, unsigned int s_n);
size_t _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
int _putchar(char c);

#endif
