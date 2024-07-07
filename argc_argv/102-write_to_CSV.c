#include "main.h"

/**
 * ends_with_csv - Check if a string ends with ".csv"
 * @str: The string to check
 * Return: 1 if the string ends with ".csv", 0 otherwise
 */
int ends_with_csv(const char *str)
{
	size_t len = strlen(str);

	return (len > 4 && strcmp(str + len - 4, ".csv") == 0);
}


/**
 * write_to_csv - writes the results to a CSV file
 * @filename: name of the CSV file
 * @results: array of results
 * @count: number of results
 * @tirage: current draw number
 */
void write_to_csv(const char *filename, char **results, int count, int tirage)
{
	FILE *file;
	int i;
	char *full_filename;

	if (ends_with_csv(filename))
	{
		full_filename = strdup(filename);
	}
	else
	{
		/* +5 for ".csv" and null terminator */
		full_filename = malloc(strlen(filename) + 5);
		if (full_filename == NULL)
		{
			printf("Error: Memory allocation failed\n");
			return;
		}
		sprintf(full_filename, "%s.csv", filename);
	}

	file = fopen(full_filename, "a");
	if (file == NULL)
	{
		printf("Error: Unable to open file %s\n", full_filename);
		free(full_filename);
		return;
	}

	fprintf(file, "Tirage %d\n", tirage);
	for (i = 0; i < count; i++)
	{
		fprintf(file, "%d,%s\n", i + 1, results[i]);
	}
	fprintf(file, "\n");

	fclose(file);
	free(full_filename);
}

