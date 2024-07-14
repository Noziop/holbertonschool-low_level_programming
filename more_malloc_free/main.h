#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

void *malloc_checked(unsigned int b);
int _strlen(char *s);
char *string_nconcat(char *s1, char *s2, unsigned int n);

#endif
