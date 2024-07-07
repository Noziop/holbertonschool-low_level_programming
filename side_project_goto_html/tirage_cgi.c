#include "main.h"

void print_html_header(void)
{
    printf("Content-type: text/html\n\n");
    printf("<html><head><title>Résultats du Tirage au Sort</title></head><body>");
}

void print_html_footer(void)
{
    printf("</body></html>");
}

int main(void)
{
    School *holberton;
    char *query_string, *token;
    char **selected_cohorts = NULL;
    int num_draws = 0, selected_cohort_count = 0;
    int i;

    print_html_header();

    query_string = getenv("QUERY_STRING");
    if (query_string == NULL)
    {
        printf("<p>Erreur: Aucun paramètre fourni</p>");
        print_html_footer();
        return (1);
    }

    holberton = initialize_school();
    if (!holberton)
    {
        printf("<p>Erreur: Initialisation de l'école échouée</p>");
        print_html_footer();
        return (1);
    }

    token = strtok(query_string, "&");
    while (token != NULL)
    {
        if (strncmp(token, "cohorts=", 8) == 0)
        {
            char *cohorts = token + 8;
            char *cohort = strtok(cohorts, ",");
            while (cohort != NULL)
            {
                selected_cohorts = realloc(selected_cohorts, (selected_cohort_count + 1) * sizeof(char *));
                selected_cohorts[selected_cohort_count++] = cohort;
                cohort = strtok(NULL, ",");
            }
        }
        else if (strncmp(token, "num_draws=", 10) == 0)
        {
            num_draws = atoi(token + 10);
        }
        token = strtok(NULL, "&");
    }

    if (selected_cohort_count == 0 || num_draws == 0)
    {
        printf("<p>Erreur: Paramètres invalides</p>");
        free_school(holberton);
        free(selected_cohorts);
        print_html_footer();
        return (1);
    }

    for (i = 0; i < selected_cohort_count; i++)
    {
        char filename[20];
        sprintf(filename, "data/%s.txt", selected_cohorts[i]);
        load_cohort_from_file(holberton, selected_cohorts[i], filename);
    }

    printf("<h1>Résultats du Tirage au Sort</h1>");
    printf("<h2>Cohortes sélectionnées:</h2><ul>");
    for (i = 0; i < selected_cohort_count; i++)
    {
        printf("<li>%s</li>", selected_cohorts[i]);
    }
    printf("</ul>");
    printf("<h2>Nombre de tirages: %d</h2>", num_draws);

    perform_draw(holberton, (const char **)selected_cohorts, selected_cohort_count, num_draws);

    free_school(holberton);
    free(selected_cohorts);
    print_html_footer();
    return (0);
}
