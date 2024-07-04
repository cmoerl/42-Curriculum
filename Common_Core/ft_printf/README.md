# ft_printf


## Overview

ft_printf is a custom implementation of the standard C library function printf. It is designed to provide similar functionality, handling various format specifiers. This project is part of the 42 School curriculum and aims to enhance understanding of variadic functions in C.

## Features

    Custom implementation of printf.
    Supports multiple format specifiers.
    Can be integrated into libft for use in other projects.

## Supported Format Specifiers

    %c : Prints a single character.
    %s : Prints a string.
    %p : Prints a pointer address in hexadecimal format.
    %d : Prints a decimal (base 10) number.
    %i : Prints an integer in base 10.
    %u : Prints an unsigned decimal (base 10) number.
    %x : Prints a number in hexadecimal (base 16) lowercase format.
    %X : Prints a number in hexadecimal (base 16) uppercase format.
    %% : Prints a percent sign.

## Installation 

### Prerequisites

    GCC or another C compiler
    Make

### Compilation

To compile the ft_printf library, clone the repository and run make:

    git clone https://github.com/cmoerl/ft_printf.git
    cd ft_printf
    make

This will generate the libftprintf.a library file.

### Makefile Rules

    make or make all: Compiles the library.
    make clean: Removes object files.
    make fclean: Removes object files and the library.
    make re: Recompiles the library from scratch.

## Usage

Include the ft_printf header in your C files and link the library when compiling your projects.

### Example

    #include "ft_printf.h"

    int main() 
    {
        ft_printf("Hello, %s!\n", "world");
        return 0;
    }

Compile your program with libftprintf.a:

    gcc -o my_program my_program.c -L. -lftprintf
    ./my_program
