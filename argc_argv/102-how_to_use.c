#include "main.h"

/**
 * how_to_use - displays help if "usage" is a given argument
 */
void how_to_use(void)
{
	printf("Usage: ./tirage_au_sort [-o output.csv] [<number_of_draws>] ");
	printf("name1 \"name 2\" etc\n");
	printf("Tips : use \"\" if you want to use space between name and forename.");
	printf("Options:\n");
	printf("  -o <file>    Output results to a CSV file\n");
	printf("  <number_of_draws>    Number of draws to perform (optional)\n");
}
