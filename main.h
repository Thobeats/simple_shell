#ifndef MAIN_H
#define MAIN_H

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void _prompt(void);
int _strcount(char *str);
char _strcmp(char *s1, char *s2);
char *_string_concat(char *str1, char *str2);
char *_getenv(char *name);


#endif
