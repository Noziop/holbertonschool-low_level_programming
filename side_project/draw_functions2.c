#include "main.h"

/**
 * perform_draw - Perform draws for selected cohorts
 * @school: Pointer to the School structure
 * @selected_cohorts: Array of selected cohort names
 * @selected_cohort_count: Number of selected cohorts
 * @num_draws: Number of draws to perform
 * @output_file: Name of the CSV file to write results (or NULL for no output)
 */
void perform_draw(School *school, const char **selected_cohorts,
				  int selected_cohort_count, int num_draws,
				  const char *output_file)
{
	int i, total_students = 0;
	Student *all_students;
	char **all_cohorts;
	int *indices;
	char ***results;

	prepare_draw_data(school, selected_cohorts, selected_cohort_count,
					  &total_students, &all_students, &all_cohorts, &indices);

	if (total_students == 0)
	{
		fprintf(stderr, "Error: No students in selected cohorts.\n");
		return;
	}

	results = safe_malloc(num_draws * sizeof(char **));
	srand(time(NULL));

	for (i = 0; i < num_draws; i++)
	{
		results[i] = safe_malloc(total_students * sizeof(char *));
		perform_single_draw(all_students, all_cohorts, indices,
							total_students, i + 1, results[i]);
	}

	if (output_file)
		write_to_csv(output_file, results, num_draws, total_students);

	free_draw_memory(results, num_draws, total_students, all_students,
					 all_cohorts, indices);
}

/**
 * free_draw_memory - Free memory allocated for draw
 * @results: Array of draw results
 * @num_draws: Number of draws
 * @total_students: Total number of students
 * @all_students: Array of all students
 * @all_cohorts: Array of all cohort names
 * @indices: Array of indices
 */
void free_draw_memory(char ***results, int num_draws, int total_students,
					  Student *all_students, char **all_cohorts, int *indices)
{
	int i, j;

	for (i = 0; i < num_draws; i++)
	{
		for (j = 0; j < total_students; j++)
			free(results[i][j]);
		free(results[i]);
	}
	free(results);
	free(all_students);
	free(all_cohorts);
	free(indices);
}
