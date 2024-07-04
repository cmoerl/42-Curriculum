# get_next_line


## Overview

get_next_line is a function designed to read lines from a file descriptor efficiently. This project helps deepen your understanding of file I/O and memory management in C.

## Features

    Reads a line from a file descriptor.
    Handles different buffer sizes.

## Requirements

### Function Prototype

char *get_next_line(int fd);

### Behavior

    Returns a line read from a file descriptor, including the newline character.
    Returns NULL when there is nothing more to read or if an error occurs.

## Installation

### Prerequisites

    GCC or another C compiler
    Make

### Compilation

To compile the get_next_line library, clone the repository and run make:

    git clone https://github.com/cmoerl/get_next_line.git
    cd get_next_line
    make

This will generate the object files for get_next_line.

### Makefile Rules

    make or make all: Compiles the source files.
    make clean: Removes object files.
    make fclean: Removes object files and the compiled library.
    make re: Recompiles the library from scratch.

## Usage

Include the get_next_line header in your C files and compile your program with the library.

## Example

    #include "get_next_line.h"
    #include <fcntl.h>
    #include <stdio.h>

    int main() 
    {
        int fd = open("test.txt", O_RDONLY);
        char *line;

        while ((line = get_next_line(fd)) != NULL) {
            printf("%s", line);
            free(line);
        }
        close(fd);
        return 0;
    }

Compile your program with the get_next_line object files:

    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 my_program.c get_next_line.c get_next_line_utils.c -o my_program
    ./my_program
