#include "main.h"
/**
*_isalpha - checks wether a letter is lowercase or not
*@c: checked character
*
*Description: checks if lowercase
*Return: 1 if not 0 if yes
*/
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
