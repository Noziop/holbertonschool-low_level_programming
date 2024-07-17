# C - Function pointers

This directory contains C programs that demonstrate the usage of function pointers as part of the Holberton School low-level programming curriculum.

## Description

Function pointers in C are powerful tools that allow you to store and manipulate addresses of functions. This project explores their usage, syntax, and applications in C programming.

## Files

- `function_pointers.h`: Header file containing prototypes for all functions used in this project.
- `0-print_name.c`: Function that prints a name using a function pointer.
- `1-array_iterator.c`: Function that executes a function given as a parameter on each element of an array.
- `2-int_index.c`: Function that searches for an integer using a comparison function.
- `3-main.c`, `3-op_functions.c`, `3-get_op_func.c`, `3-calc.h`: Program that performs simple operations (+, -, *, /, %).

## Learning Objectives

By the end of this project, you should be able to:

- Understand what function pointers are and how to use them
- Explain what a function pointer holds
- Identify where a function pointer points to in virtual memory
- Use function pointers to create flexible and dynamic code

## Requirements

- All files are compiled on Ubuntu 20.04 LTS using gcc, with the options -Wall -Werror -Wextra -pedantic -std=gnu89
- Code follows the Betty style
- No global variables are allowed
- No more than 5 functions per file
- The only C standard library functions allowed are malloc, free, and exit
- All header files should be include guarded

## Usage

To compile the C files, use:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o [output_filename]

## Author

* **Noziop** - [GitHub Profile](https://github.com/Noziop)

## Acknowledgments

* **Holberton School** - providing the opportunity to learn and grow as a software engineer

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


<p align="center">
  <img
   src="https://cdn.prod.website-files.com/64107f65f30b69371e3d6bfa/65c6179aa44b63fa4f31e7ad_Holberton-Logo-Cherry.svg"
   alt="Holberton School logo">
</p>