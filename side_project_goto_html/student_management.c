#include "main.h"

/**
 * add_student - Add a new student to a cohort
 * @school: Pointer to the School structure
 * @cohort_name: Name of the cohort to add the student to
 * @student_name: Name of the new student
 */
void add_student(School *school, const char *cohort_name,
				 const char *student_name)
{
	Cohort *cohort = find_cohort(school, cohort_name);
	Student *new_students;

	if (!cohort)
	{
		printf("Error: Cohort %s not found\n", cohort_name);
		return;
	}

	new_students = safe_malloc((cohort->student_count + 1) * sizeof(Student));
	if (cohort->students)
	{
		memcpy(new_students, cohort->students,
			   cohort->student_count * sizeof(Student));
		free(cohort->students);
	}
	cohort->students = new_students;

	strncpy(cohort->students[cohort->student_count].name, student_name,
			MAX_NAME_LENGTH - 1);
	cohort->students[cohort->student_count].name[MAX_NAME_LENGTH - 1] = '\0';
	cohort->students[cohort->student_count].selected_count = 0;
	cohort->student_count++;
}

/**
 * print_school_info - Print information about the school and its cohorts
 * @school: Pointer to the School structure
 */
void print_school_info(School *school)
{
	int i, j;

	printf("School Information:\n");
	for (i = 0; i < school->cohort_count; i++)
	{
		printf("Cohort %s:\n", school->cohorts[i].name);
		for (j = 0; j < school->cohorts[i].student_count; j++)
		{
			printf("  - %s\n", school->cohorts[i].students[j].name);
		}
		printf("\n");
	}
}

