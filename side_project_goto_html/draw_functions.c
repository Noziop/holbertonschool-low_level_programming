#include "main.h"

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

void perform_single_draw(Student *all_students, char **all_cohorts, int *indices,
                         int total_students, int draw_number)
{
    int j, k;

    shuffle_array(indices, total_students);

    printf("<h3>Tirage %d:</h3><ol>", draw_number);
    for (j = 0; j < total_students; j++)
    {
        k = indices[j];
        printf("<li>%s (Cohort: %s)</li>", all_students[k].name, all_cohorts[k]);
    }
    printf("</ol>");
}

void perform_draw(School *school, const char **selected_cohorts,
                  int selected_cohort_count, int num_draws)
{
    int i, total_students = 0;
    Student *all_students;
    char **all_cohorts;
    int *indices;

    prepare_draw_data(school, selected_cohorts, selected_cohort_count,
                      &total_students, &all_students, &all_cohorts, &indices);

    if (total_students == 0)
    {
        printf("<p>Erreur : Aucun étudiant dans les cohortes sélectionnées.</p>");
        return;
    }

    srand(time(NULL));

    printf("<h2>Résultats des tirages :</h2>");
    for (i = 0; i < num_draws; i++)
    {
        perform_single_draw(all_students, all_cohorts, indices, total_students, i + 1);
    }

    free(all_students);
    free(all_cohorts);
    free(indices);
}
