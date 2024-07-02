#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: string to be counted
 * Return: count of the string
 */

int _strlen_recursion(char *s)
{
	return ((*s != '\0') ? 1 + _strlen_recursion(s + 1) : (0));
}
