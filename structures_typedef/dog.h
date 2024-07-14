#ifndef DOG_H
#define DOG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct dog - A new type describing a dog.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/* Define a new type dog_t as an alias for struct dog */
typedef struct dog dog_t;

/* Functions prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
void free_dog(dog_t *d);

#endif /* DOG_H */
