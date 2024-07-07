#include "main.h"

void print_usage(const char *program_name)
{
	printf("Usage: %s [-o output.csv] [-c cohort_name] <number_of_draws> <cohort1> [cohort2] ...\n", program_name);
	printf("Options:\n");
	printf("  -o <file>    Output results to a CSV file\n");
	printf("  -c <cohort>  Create a new cohort\n");
}

int main(int argc, char *argv[])
{
	School *holberton;
	char *output_file = NULL;
	int num_draws, i, arg_index = 1, selected_cohort_count;
	const char **selected_cohorts;

	if (argc < 3)
	{
		print_usage(argv[0]);
		return 1;
	}

	holberton = initialize_school();
	if (!holberton)
		return 1;

	if (strcmp(argv[1], "-c") == 0)
	{
		if (argc != 3)
		{
			print_usage(argv[0]);
			free_school(holberton);
			return 1;
		}
		if (create_new_cohort(holberton, argv[2]))
		{
			free_school(holberton);
			return 0;
		}
		free_school(holberton);
		return 1;
	}

	if (strcmp(argv[1], "-o") == 0)
	{
		if (argc < 5)
		{
			print_usage(argv[0]);
			free_school(holberton);
			return 1;
		}
		output_file = argv[2];
		arg_index = 3;
	}

	num_draws = atoi(argv[arg_index++]);
	if (num_draws <= 0)
	{
		printf("Error: Invalid number of draws\n");
		free_school(holberton);
		return 1;
	}

	selected_cohorts = (const char **)&argv[arg_index];
	selected_cohort_count = argc - arg_index;

	for (i = 0; i < selected_cohort_count; i++)
	{
		char filename[20];
		sprintf(filename, "%s.txt", selected_cohorts[i]);
		load_cohort_from_file(holberton, selected_cohorts[i], filename);
	}

	print_school_info(holberton);

	perform_draw(holberton, selected_cohorts, selected_cohort_count, num_draws, output_file);

	free_school(holberton);
	return 0;
}

