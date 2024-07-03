#include "main.h"

/**
 * wildcmp - compare two string
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if identical
 *			0 if not
 */
int wildcmp(char *s1, char *s2)
{
	/* Si les deux chaînes sont vides, elles sont identiques */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* Si s2 commence par '*' */
	if (*s2 == '*')
	{
		/* On regarde si le reste de s2 correspond à s1 */
		/* OU si '*' remplace un ou plusieurs caractères de s1 */

		return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));
	}

	/* Si les caractères actuels correspondent ou si s2 a un '?' */
	if (*s1 == *s2 || *s2 == '?')
	{
		/* On continue avec les caractères suivants */
		return ((*s1 != '\0') && wildcmp(s1 + 1, s2 + 1));
	}

	/* Si rien ne correspond, les chaînes ne sont pas identiques */
	return (0);
}
