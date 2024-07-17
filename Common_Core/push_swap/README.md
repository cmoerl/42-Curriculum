# push_swap


## Overview

push_swap is a program designed to sort a stack of integers using a predefined set of operations. The goal is to sort the stack with the fewest possible moves.

## Installation

### Prerequisites

    Unix-like operating system (Linux, macOS).
    GCC compiler.
    Make utility.

### Compilation

To compile the project, clone the repository and run make:

    git clone https://github.com/cmoerl/push_swap.git
    cd push_swap
    make

This will generate an executable named push_swap.

## Usage

To run the program, use the following command:

    ./push_swap [numbers...]

### Parameters

    [numbers...]: A list of integers to be sorted.

### Example

    ./push_swap 2 1 3 6 5 8

This command will output the sequence of operations needed to sort the stack.

### Common Operations

    sa: Swap the first two elements at the top of stack a.
    sb: Swap the first two elements at the top of stack b.
    ss: sa and sb at the same time.
    pa: Take the first element at the top of b and put it at the top of a.
    pb: Take the first element at the top of a and put it at the top of b.
    ra: Shift all elements of stack a up by one.
    rb: Shift all elements of stack b up by one.
    rr: ra and rb at the same time.
    rra: Shift all elements of stack a down by one.
    rrb: Shift all elements of stack b down by one.
    rrr: rra and rrb at the same time.

## Error Handling

    If no parameters are given, the program should not display anything.
    If an error occurs, the program displays "Error" followed by a newline on standard error.
    Errors to handle include non-integer arguments, arguments exceeding integer limits, and duplicate arguments.

## Makefile Rules

    make or make all: Compiles the program.
    make clean: Removes object files.
    make fclean: Removes object files and the executable.
    make re: Recompiles the project from scratch.
