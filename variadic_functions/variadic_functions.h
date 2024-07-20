#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct printer - Struct to hold print function and its corresponding symbol
 * @symbol: The symbol representing the data type
 * @print: The function to print the data type
 *
 * Description: This struct is used to map symbols to their corresponding
 * print functions in the print_all function.
 */
typedef struct printer
{
	char *symbol;
	void (*print)(va_list);
} printer_t;

/* functions prototypes : */

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
void print_all(const char * const format, ...);

#endif /* VARIADIC_FUNTIONS_H */
