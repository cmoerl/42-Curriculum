# Pipex


## Overview

Pipex is a project designed to emulate the behavior of shell pipelines. By using this program, you will gain a deeper understanding of how UNIX pipes work by implementing a program that mimics the shell command:

    < file1 cmd1 | cmd2 > file2

## Installation

### Prerequisites

    Unix-like operating system (Linux, macOS).
    GCC compiler.
    Make utility.

### Compilation

To compile the project, clone the repository and run make:

    git clone https://github.com/cmoerl/pipex.git
    cd pipex
    make

This will generate an executable named pipex.

## Usage

To run the program, use the following command:

    ./pipex file1 cmd1 cmd2 file2

### Parameters

    file1: Name of the input file.
    cmd1: First shell command to execute.
    cmd2: Second shell command to execute.
    file2: Name of the output file.

### Example

    ./pipex infile "ls -l" "wc -l" outfile

This command behaves like the following shell command:

    < infile ls -l | wc -l > outfile

Another Example:

    ./pipex infile "grep a1" "wc -w" outfile

This command behaves like the following shell command:

    < infile grep a1 | wc -w > outfile

## Makefile Rules

    make or make all: Compiles the program.
    make clean: Removes object files.
    make fclean: Removes object files and the executable.
    make re: Recompiles the project from scratch.
