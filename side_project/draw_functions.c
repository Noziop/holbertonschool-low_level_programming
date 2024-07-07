#include "main.h"

/**
 * shuffle_array - Shuffle an array of integers
 * @array: The array to shuffle
 * @n: The number of elements in the array
 */
void shuffle_array(int *array, int n)
{
	int i, j, temp;

	for (i = n - 1; i > 0; i--)
	{
		j = rand() % (i + 1);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

/**
 * write_to_csv - Write draw results to a CSV file
 * @filename: Name of the CSV file
 * @results: Array of draw results
 * @num_draws: Number of draws
 * @students_per_draw: Number of students in each draw
 */
void write_to_csv(const char *filename, char ***results, int num_draws,
				  int students_per_draw)
{
	FILE *file;
	int i, j;
	char *full_filename;
	size_t filename_len = strlen(filename);

	if (filename_len >= 4 && strcmp(filename + filename_len - 4, ".csv") == 0)
	{
		full_filename = safe_strdup(filename);
	}
	else
	{
		full_filename = safe_malloc(filename_len + 5); /* +5 for ".csv\0" */
		sprintf(full_filename, "%s.csv", filename);
	}

	file = fopen(full_filename, "w");
	if (!file)
	{
		printf("Error: Unable to open file %s for writing\n", full_filename);
		free(full_filename);
		return;
	}

	for (i = 0; i < num_draws; i++)
	{
		fprintf(file, "Draw %d\n", i + 1);
		for (j = 0; j < students_per_draw; j++)
			fprintf(file, "%d,%s\n", j + 1, results[i][j]);
		fprintf(file, "\n");
	}

	fclose(file);
	printf("Results written to %s\n", full_filename);
	free(full_filename);
}

/**
 * prepare_draw_data - Prepare data for the draw
 * @school: Pointer to the School structure
 * @selected_cohorts: Array of selected cohort names
 * @selected_cohort_count: Number of selected cohorts
 * @total_students: Pointer to store total number of students
 * @all_students: Pointer to store all students
 * @all_cohorts: Pointer to store all cohort names
 * @indices: Pointer to store indices for shuffling
 */
void prepare_draw_data(School *school, const char **selected_cohorts,
					   int selected_cohort_count, int *total_students,
					   Student **all_students, char ***all_cohorts, int **indices)
{
	int i, j, current_index = 0;

	*total_students = 0;
	for (i = 0; i < selected_cohort_count; i++)
	{
		Cohort *cohort = find_cohort(school, selected_cohorts[i]);

		if (cohort)
			*total_students += cohort->student_count;
	}

	*all_students = safe_malloc(*total_students * sizeof(Student));
	*all_cohorts = safe_malloc(*total_students * sizeof(char *));
	*indices = safe_malloc(*total_students * sizeof(int));

	for (i = 0; i < selected_cohort_count; i++)
	{
		Cohort *cohort = find_cohort(school, selected_cohorts[i]);

		if (cohort)
		{
			for (j = 0; j < cohort->student_count; j++)
			{
				(*all_students)[current_index] = cohort->students[j];
				(*all_cohorts)[current_index] = cohort->name;
				(*indices)[current_index] = current_index;
				current_index++;
			}
		}
	}
}

/**
 * perform_single_draw - Perform a single draw
 * @all_students: Array of all students
 * @all_cohorts: Array of all cohort names
 * @indices: Array of indices for shuffling
 * @total_students: Total number of students
 * @draw_number: Current draw number
 * @results: Array to store results
 */
void perform_single_draw(Student *all_students, char **all_cohorts,
		int *indices, int total_students, int draw_number, char **results)
{
	int j, k;

	shuffle_array(indices, total_students);

	printf("Draw %d:\n", draw_number);
	for (j = 0; j < total_students; j++)
	{
		k = indices[j];
		printf("%d. %s (Cohort: %s)\n", j + 1, all_students[k].name,
			   all_cohorts[k]);
		results[j] = safe_malloc(strlen(all_students[k].name) +
								 strlen(all_cohorts[k]) + 15);
		sprintf(results[j], "%s (Cohort: %s)",
				all_students[k].name, all_cohorts[k]);
	}
	printf("\n");
}
