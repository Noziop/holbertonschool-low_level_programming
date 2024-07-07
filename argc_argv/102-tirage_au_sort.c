#include "main.h"

/**
 * allocate_memory - allocate memory for picked and results arrays
 * @picked: pointer to picked array
 * @results: pointer to results array
 * @size: size of arrays
 * Return: 0 if success, 1 if error
 */
int allocate_memory(bool **picked, char ***results, int size)
{
	*picked = (bool *)malloc(size * sizeof(bool));
	if (*picked == NULL)
	{
		printf("Error: memory allocation failed\n");
		return (1);
	}

	*results = malloc(size * sizeof(char *));
	if (*results == NULL)
	{
		printf("Error: Memory allocation failed\n");
		free(*picked);
		return (1);
	}

	return (0);
}

/**
 * free_memory - free allocated memory
 * @picked: picked array
 * @results: results array
 */
void free_memory(bool *picked, char **results)
{
	free(picked);
	free(results);
}

/**
 * parse_arguments - parse command line arguments
 * @argc: number of arguments
 * @argv: array of arguments
 * @start_index: pointer to start index
 * @out_file: pointer to output file name
 * Return: number of draws, or -1 if error
 */
int parse_arguments(int argc, char *argv[], int *start_index, char **out_file)
{
	int num_tirages = 1;

	if (argc == 2 && strcmp(argv[1], "usage") == 0)
	{
		how_to_use();
		return (-1);
	}

	if (argc > 2 && strcmp(argv[1], "-o") == 0)
	{
		*out_file = argv[2];
		*start_index = 3;
	}

	if (argc < *start_index + 2)
	{
		printf("Error: we need at least 2 names to perform a random sort out\n");
		return (-1);
	}

	if (isdigit(argv[*start_index][0]))
	{
		num_tirages = atoi(argv[*start_index]);
		(*start_index)++;
	}

	return (num_tirages);
}

/**
 * perform_draw - perform a single draw
 * @argv: array of arguments
 * @picked: array of picked flags
 * @results: array to store results
 * @start_index: start index for names
 * @argc: number of arguments
 */
void perform_draw(char **argv, bool *picked, char **results,
		int start_index, int argc)
{
	int random_index, count = 0;
	int i;

	for (i = 0; i < argc - start_index; i++)
		picked[i] = false;

	while (count < argc - start_index)
	{
		do {
			random_index = rand() % (argc - start_index);
		} while (picked[random_index]);

		picked[random_index] = true;
		results[count] = argv[random_index + start_index];
		count++;

		printf("%d - %s\n", count, results[count - 1]);
	}
	printf("\n");
}

/**
 * main - random sort the given arguments
 * @argc: number of given arguments
 * @argv: array of given arguments
 * Return: 0 if success, 1 if error
 */
int main(int argc, char *argv[])
{
	int start_index = 1, num_tirages;
	char *output_file = NULL;
	bool *picked;
	char **results;
	int t;

	num_tirages = parse_arguments(argc, argv, &start_index, &output_file);
	if (num_tirages == -1)
		return (1);

	if (allocate_memory(&picked, &results, argc - start_index))
		return (1);

	srand(time(NULL));

	for (t = 0; t < num_tirages; t++)
	{
		printf("Tirage %d:\n", t + 1);
		perform_draw(argv, picked, results, start_index, argc);

		if (output_file)
			write_to_csv(output_file, results, argc - start_index, t + 1);
	}

	free_memory(picked, results);

	return (0);
}
