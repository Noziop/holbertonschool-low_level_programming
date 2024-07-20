# C - Variadic Functions

## Description
This project explores variadic functions in C, which are functions that can accept a variable number of arguments. It demonstrates the use of `stdarg.h` and implements various utility functions using this concept.

## Files

| File | Description |
| ------ | ------ |
| variadic_functions.h | Header file containing function prototypes and necessary includes |
| 0-sum_them_all.c | Function that returns the sum of all its parameters |
| 1-print_numbers.c | Function that prints numbers, followed by a new line |
| 2-print_strings.c | Function that prints strings, followed by a new line |
| 3-print_all.c | Function that prints anything |

## Requirements
- Compiled on Ubuntu 20.04 LTS using gcc
- Compilation flags: -Wall -Werror -Wextra -pedantic -std=gnu89
- Code should use the Betty style

## Compilation and Testing
To compile each function with its corresponding main file, use:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 [main-file.c] [function-file.c] -o [output]

Example:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-sum_them_all.c -o sum


## Usage Examples

### 0-sum_them_all.c
```c
#include <stdio.h>
#include "variadic_functions.h"

int main(void)
{
    int sum;

    sum = sum_them_all(4, 98, 1024, 402, -1024);
    printf("Sum: %d\n", sum);
    return (0);
}
```
```bash
Output: Sum: 500
```
```c
#include "variadic_functions.h"

int main(void)
{
    print_all("ceis", 'H', 0, "Hello", "World");
    return (0);
}
```
```bash
Output: H, 0, Hello, World
```

## Learning Objectives
- Understanding variadic functions in C
- Using va_start, va_arg, and va_end macros
- Implementing functions that can handle a variable number of arguments

## Author
* **Noziop** - [GitHub Profile](https://github.com/Noziop)

## Acknowledgments
* **Holberton School** - providing the opportunity to learn and grow as a software engineer

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

<p align="center">
  <img src="https://cdn.prod.website-files.com/64107f65f30b69371e3d6bfa/65c6179aa44b63fa4f31e7ad_Holberton-Logo-Cherry.svg" alt="Holberton School logo">
</p>