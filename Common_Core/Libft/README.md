# Libft


## Introduction

Libft is a custom implementation of many functions from the standard C library, along with additional utility functions. This library is designed to be a helpful resource for your future C programming projects.

## Features

    Reimplementation of standard C library functions.
    Additional utility functions for string manipulation, memory management, and more.

## Installation

### Prerequisites

    GCC or another C compiler
    Make

### Compilation

To compile the libft library, clone the repository and run make:

    git clone https://github.com/yourusername/libft.git
    cd libft
    make

This will generate the libft.a library file.

### Makefile Rules

    make or make all: Compiles the library.
    make clean: Removes object files.
    make fclean: Removes object files and the library.
    make re: Recompiles the library from scratch.

## Usage

Include the libft header in your C files and link the library when compiling your projects.

## Example

#include "libft.h"

    int main() 
    {
        char *str = ft_strdup("Hello, World!");
        if (str) {
            ft_putstr_fd(str, 1);
            ft_putchar_fd('\n', 1);
            free(str);
        }
        return 0;
    }

Compile your program with libft:

    gcc -Wall -Wextra -Werror -o my_program my_program.c -L. -lft
    ./my_program

## Implemented Functions

### Part 1: Libc Functions

These functions replicate standard C library functions with the prefix ft_:

    ft_isalpha - Checks for an alphabetic character.
    ft_isdigit - Checks for a digit (0 through 9).
    ft_isalnum - Checks for an alphanumeric character.
    ft_isascii - Checks whether c fits into the ASCII character set.
    ft_isprint - Checks for any printable character.
    ft_strlen - Computes the length of the string.
    ft_memset - Fills a byte string with a byte value.
    ft_bzero - Erases the data in the n bytes of the memory.
    ft_memcpy - Copies n bytes from memory area src to memory area dest.
    ft_memmove - Copies n bytes from memory area src to memory area dest (with overlapping).
    ft_strlcpy - Copies up to dstsize - 1 characters from the string src to dst.
    ft_strlcat - Appends the src string to the dst string.
    ft_toupper - Converts a lower-case letter to the corresponding upper-case letter.
    ft_tolower - Converts an upper-case letter to the corresponding lower-case letter.
    ft_strchr - Locates the first occurrence of c in the string s.
    ft_strrchr - Locates the last occurrence of c in the string s.
    ft_strncmp - Compares not more than n characters from strings s1 and s2.
    ft_memchr - Locates the first occurrence of c in the n bytes of the string s.
    ft_memcmp - Compares byte string s1 against byte string s2.
    ft_strnstr - Locates a substring in a string (with size-bounded search).
    ft_atoi - Converts the initial portion of the string pointed to by str to int.

Additional memory management functions:

    ft_calloc - Allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory.
    ft_strdup - Returns a pointer to a new string which is a duplicate of the string s.

### Part 2: Additional Functions

Utility functions to extend the functionality of your library:

    ft_substr - Allocates and returns a substring from the string s.
    ft_strjoin - Allocates and returns a new string, result of the concatenation of s1 and s2.
    ft_strtrim - Allocates and returns a copy of s1 with the characters specified in set removed from the beginning and the end.
    ft_split - Allocates and returns an array of strings obtained by splitting s using the character c as a delimiter.
    ft_itoa - Allocates and returns a string representing the integer n.
    ft_strmapi - Applies the function f to each character of the string s to create a new string.
    ft_striteri - Applies the function f to each character of the string s, passing its index as the first argument.
    ft_putchar_fd - Outputs the character c to the given file descriptor.
    ft_putstr_fd - Outputs the string s to the given file descriptor.
    ft_putendl_fd - Outputs the string s to the given file descriptor, followed by a newline.
    ft_putnbr_fd - Outputs the integer n to the given file descriptor.
