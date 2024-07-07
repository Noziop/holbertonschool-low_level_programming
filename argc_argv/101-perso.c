#include "main.h"

/**
 * main - calculates the average of numbers passed as arguments
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on error
 */

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Erreur : Veuillez fournir au moins un nombre.\n");
		return (1);
	}

	float sum = 0;
	int valid_count = 0;

	for (int i = 1; i < argc; i++)
	{
		if (is_valid_float(argv[i]))
		{
			sum += atof(argv[i]);
			valid_count++;
		}
		else
		{
			printf("Erreur : '%s' n'est pas un nombre valide.\n", argv[i]);
			return (1);
		}
	}

	if (valid_count > 0)
	{
		float average = sum / valid_count;

		printf("La moyenne est : %.2f\n", average);
	}

	return (0);
}

/**
 * is_valid_float - checks if str contains only float value
 * @str: string to be tested
 *
 * Return: 0 if no
 *			1 if yes
 */

int is_valid_float(const char *str)
{
	char *endptr;

	errno = 0;

	float val = strtof(str, &endptr);

	if (errno == ERANGE)
		return (0);
	if (endptr == str)
		return (0);
	if (*endptr != '\0')
		return (0);

	return (1);
}

	return (1);
}

