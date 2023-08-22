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
char **_tokenize(char *lineptr, char *lineptr2, const char *dilem);
int _check(char **argv, char *name);
char *_error(char **argv, char *name);
void _execute(char **argv);
char *_pathFinder(char *exe);
char *_getenv(char *var);
void _print_env(void);

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
int _putchar(char c);

#endif
