#include "main.h"
/**
*_islower - checks wether a letter is lowercase or not
*@c: checked character
*
*Description: checks if lowercase
*Return: 1 if not 0 if yes
*/
int _islower(int c)
{
	if (c <= 'a' || c >= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
