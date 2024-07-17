#include "function_pointers.h"

/**
 * print_name - Prints a name using a given function
 * @name: The name to be printed
 * @f: A pointer to the function that will print the name
 *
 * Description: This function takes a name
 *  and a function pointer as parameters.
 * It then calls the function pointed to by f, passing it the name.
 */

void print_name(char *name, void (*f)(char *))
{
	if (name && f)
	{
		f(name);
	}
}
