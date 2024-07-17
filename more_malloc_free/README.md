# C - More malloc, free

This directory contains C programs that demonstrate advanced usage of dynamic memory allocation using `malloc`, `free`, and related functions.

## Description

This project builds upon the basic `malloc` and `free` concepts, introducing more complex memory management techniques and functions such as `calloc`, `realloc`, and strategies to handle memory allocation failures.

## Files

- `0-malloc_checked.c`: Function that allocates memory using malloc.
- `1-string_nconcat.c`: Function that concatenates two strings.
- `2-calloc.c`: Function that allocates memory for an array, using malloc.
- `3-array_range.c`: Function that creates an array of integers.
- `100-realloc.c`: Function that reallocates a memory block using malloc and free.
- `101-mul.c`: Program that multiplies two positive numbers.

## Learning Objectives

- How to use the `exit` function
- What are the functions `calloc` and `realloc` from the standard library and how to use them
- Understanding of when and why to use `malloc` for arrays vs. using it for strings
- How to handle memory allocation failures

## Requirements

- All files are compiled on Ubuntu 20.04 LTS using gcc, with the options -Wall -Werror -Wextra -pedantic -std=gnu89
- Code follows the Betty style
- No global variables are allowed
- No more than 5 functions per file
- Only allowed C standard library functions are malloc, free, and exit
- You are allowed to use _putchar

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