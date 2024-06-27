#include "main.h"

/**
 * _atoi - from a char string, extract numbers, and convert into int
 *@s: string to be tested
*
* Return: 0 if success
*/
int _atoi(char *s)
{
	int i;
	int n = 1;
	int result = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] <= 48 && s[i] >= 57)
		{
			return (0);
		}
		else if (s[i] == 45)
		{
			if (s[i + 1] >= 48 && s[i + 1] <= 57)
			{
				n = -n;
			}
			else
			continue;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		result = result * 10 + ((int)s[i] - 48);
	}

	return (n * result);
}
