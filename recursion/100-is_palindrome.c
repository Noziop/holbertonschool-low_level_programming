#include "main.h"

/**
 * is_palindrome - checks if string is palindrome
 * @s: string to be tested
 * Return: 1 if yes
 *			0 if no
 */

int is_palindrome(char *s)
{
	int len = 0;

	if (*s == '\0' || *(s + 1) == '\0')
		return (1);

	len = 1 + is_palindrome_helper(s + 1);

	return (check_palindrome(s, 0, len - 1));
}

/**
 * check_palindrome - checks if string is palindrome
 * @s: string to be tested
 * @start: start of the string
 * @end: end of the string
 * Return: 1 if yes
 *			0 if no
 */

int check_palindrome(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return (check_palindrome(s, start + 1, end - 1));
}

/**
 * is_palindrome_helper - find the length of the string
 * @s: string to be tested
 * Return: 1 if yes
 *			0 if no
 */

int is_palindrome_helper(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + is_palindrome_helper(s + 1));
}
