#include "main.h"

void add_cohort(School *school, const char *cohort_name)
{
	Cohort *new_cohorts;

	new_cohorts = safe_malloc((school->cohort_count + 1) * sizeof(Cohort));
	if (school->cohorts)
	{
		memcpy(new_cohorts, school->cohorts, school->cohort_count * sizeof(Cohort));
		free(school->cohorts);
	}
	school->cohorts = new_cohorts;

	strncpy(school->cohorts[school->cohort_count].name, cohort_name, MAX_COHORT_NAME_LENGTH - 1);
	school->cohorts[school->cohort_count].name[MAX_COHORT_NAME_LENGTH - 1] = '\0';
	school->cohorts[school->cohort_count].students = NULL;
	school->cohorts[school->cohort_count].student_count = 0;
	school->cohort_count++;
}

Cohort *find_cohort(School *school, const char *cohort_name)
{
	int i;

	for (i = 0; i < school->cohort_count; i++)
	{
		if (strcmp(school->cohorts[i].name, cohort_name) == 0)
			return &school->cohorts[i];
	}
	return NULL;
}

void load_cohort_from_file(School *school, const char *cohort_name, const char *filename)
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

int create_new_cohort(School *school, const char *cohort_name)
{
	char filename[20];
	FILE *file;

	if (find_cohort(school, cohort_name) != NULL)
	{
		printf("Error: Cohort %s already exists\n", cohort_name);
		return 0;
	}

	snprintf(filename, sizeof(filename), "%s.txt", cohort_name);
	file = fopen(filename, "w");
	if (!file)
	{
		printf("Error: Unable to create file %s\n", filename);
		return 0;
	}
	fclose(file);

	add_cohort(school, cohort_name);
	printf("Cohort %s created successfully\n", cohort_name);
	return 1;
}

