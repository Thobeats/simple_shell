#ifndef MAIN_H
#define MAIN_H

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctype.h>

int _prompt(char **name);
int _strcount(char *str);
char _strcmp(char *s1, char *s2);
char *_string_concat(char *str1, char *str2);
char *_getenv(char *name);
char *_strcpy(char *src, char *dest);
char *get_location(char *command);
char *remove_space(char *path);
void handle_command(char *command, char **args);
void exit_fnc(int stat_code);

#endif
