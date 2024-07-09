#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structures.h"

/* school_init.c */
School *initialize_school(void);
void free_school(School *school);

/* cohort_management.c */
void add_cohort(School *school, const char *cohort_name);
Cohort *find_cohort(School *school, const char *cohort_name);
void load_cohort_from_file(School *school, const char *cohort_name, const char *filename);
int create_new_cohort(School *school, const char *cohort_name);

/* student_management.c */
void add_student(School *school, const char *cohort_name, const char *student_name);
void print_school_info(School *school);

/* draw_functions.c */
void perform_draw(School *school, const char **selected_cohorts,
int selected_cohort_count, int num_draws, const char +*output_file);
void shuffle_array(int *array, int n);
void write_to_csv(const char *filename, char ***results, int num_draws,
                  int students_per_draw);
void prepare_draw_data(School *school, const char **selected_cohorts,
                       int selected_cohort_count, int *total_students,
                       Student **all_students, char ***all_cohorts, int **indices);
void perform_single_draw(Student *all_students, char **all_cohorts,
        int *indices, int total_students, int draw_number, char **results);
void free_draw_memory(char ***results, int num_draws, int total_students,
                      Student *all_students, char **all_cohorts, int *indices);

/* utility_functions.c */
void *safe_malloc(size_t size);
char *safe_strdup(const char *str);

#endif /* MAIN_H */

