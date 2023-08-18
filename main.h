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
#include <dirent.h>

int main(int argc, char **argv);
void _execute(char **argv);
char *_pathFinder(char *exe);
char *_getenv(const char *var);

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _putchar(char c);

#endif
