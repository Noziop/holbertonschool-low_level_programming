#ifndef STRUCTURES_H
#define STRUCTURES_H

#define MAX_NAME_LENGTH 50
#define MAX_COHORT_NAME_LENGTH 10

/**
 * struct Student - Represents a student in the school
 * @name: Name of the student
 * @selected_count: Number of times the student has been selected in draws
 *
 * Description: This structure holds information about a single student,
 * including their name and how many times they've been selected in draws.
 */
typedef struct Student
{
	char name[MAX_NAME_LENGTH];
	int selected_count;
} Student;

/**
 * struct Cohort - Represents a cohort in the school
 * @name: Name of the cohort
 * @students: Array of students in the cohort
 * @student_count: Number of students in the cohort
 *
 * Description: This structure holds information about a cohort,
 * including its name, the students it contains, and the number of students.
 */
typedef struct Cohort
{
	char name[MAX_COHORT_NAME_LENGTH];
	Student *students;
	int student_count;
} Cohort;

/**
 * struct School - Represents the entire school
 * @cohorts: Array of cohorts in the school
 * @cohort_count: Number of cohorts in the school
 *
 * Description: This structure represents the entire school,
 * containing all cohorts and their respective information.
 */
typedef struct School
{
	Cohort *cohorts;
	int cohort_count;
} School;

#endif /* STRUCTURES_H */
