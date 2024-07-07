#include "main.h"

/**
 * add_cohort - Add a new cohort to the school
 * @school: Pointer to the School structure
 * @cohort_name: Name of the new cohort
 */
void add_cohort(School *school, const char *cohort_name)
{
	Cohort *new_cohorts;

	new_cohorts = safe_malloc((school->cohort_count + 1) * sizeof(Cohort));
	if (school->cohorts)
	{
		memcpy(new_cohorts, school->cohorts,
			   school->cohort_count * sizeof(Cohort));
		free(school->cohorts);
	}
	school->cohorts = new_cohorts;

	strncpy(school->cohorts[school->cohort_count].name, cohort_name,
			MAX_COHORT_NAME_LENGTH - 1);
	school->cohorts[school->cohort_count].name[MAX_COHORT_NAME_LENGTH - 1] = '\0';
	school->cohorts[school->cohort_count].students = NULL;
	school->cohorts[school->cohort_count].student_count = 0;
	school->cohort_count++;
}

/**
 * find_cohort - Find a cohort by name
 * @school: Pointer to the School structure
 * @cohort_name: Name of the cohort to find
 *
 * Return: Pointer to the found Cohort, or NULL if not found
 */
Cohort *find_cohort(School *school, const char *cohort_name)
{
	int i;

	for (i = 0; i < school->cohort_count; i++)
	{
		if (strcmp(school->cohorts[i].name, cohort_name) == 0)
			return (&school->cohorts[i]);
	}
	return (NULL);
}

/**
 * load_cohort_from_file - Load students for a cohort from a file
 * @school: Pointer to the School structure
 * @cohort_name: Name of the cohort to load
 * @filename: Name of the file containing student names
 */
void load_cohort_from_file(School *school, const char *cohort_name,
						   const char *filename)
{
	FILE *file;
	char line[MAX_NAME_LENGTH];

	file = fopen(filename, "r");
	if (!file)
	{
		printf("Error: Unable to open file %s\n", filename);
		return;
	}

	add_cohort(school, cohort_name);

	while (fgets(line, sizeof(line), file))
	{
		line[strcspn(line, "\n")] = 0; /* Remove newline */
		if (strlen(line) > 0)
		{
			add_student(school, cohort_name, line);
		}
	}

	fclose(file);
}

