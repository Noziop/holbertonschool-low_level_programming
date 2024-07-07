#include "main.h"

/**
 * initialize_school - Initialize a new School structure
 *
 * Return: Pointer to the new School, or NULL on failure
 */
School *initialize_school(void)
{
	School *school = safe_malloc(sizeof(School));

	if (school)
	{
		school->cohorts = NULL;
		school->cohort_count = 0;
	}
	return (school);
}

/**
 * free_school - Free all memory associated with a School structure
 * @school: Pointer to the School to free
 */
void free_school(School *school)
{
	int i, j;

	if (!school)
		return;

	for (i = 0; i < school->cohort_count; i++)
	{
		for (j = 0; j < school->cohorts[i].student_count; j++)
		{
			/* Free any dynamically allocated student data here if needed */
		}
		free(school->cohorts[i].students);
	}
	free(school->cohorts);
	free(school);
}

