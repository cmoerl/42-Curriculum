# Fract-ol


## Introduction

Fract-ol is a graphical program that explores the beauty of fractals. By utilizing the MiniLibX library, this project aims to render and interact with various fractal sets, including the Mandelbrot and Julia sets.

## Features

    Render the Mandelbrot and Julia fractals.
    Interactive zooming using the mouse wheel.
    Ability to display different Julia sets based on user-provided parameters.
    Color variations to indicate fractal depth.

## Installation

### Prerequisites

    GCC or another C compiler
    Make
    MiniLibX library 

#### MiniLibX Library

Fract-ol utilizes the MiniLibX library, a simple and easy-to-use library that provides basic graphics functionality. You can obtain the library from [this repository](https://github.com/42Paris/minilibx-linux). After downloading, place the library's directory in the fract-ol directory.

### Compilation

To compile the fract-ol program, clone the repository and run make:

    git clone https://github.com/cmoerl/fract-ol.git
    cd fract-ol
    make

This will generate the fractol executable.

### Makefile Rules

    make or make all: Compiles the program.
    make clean: Removes object files.
    make fclean: Removes object files and the executable.
    make re: Recompiles the program from scratch.

## Usage

Run the program with the desired fractal type as an argument:

    ./fractol <fractal_type> [options]

### Example

To display the Mandelbrot set:

    ./fractol mandelbrot

To display a Julia set with specific parameters:

    ./fractol julia <real_part> <imaginary_part>

### Controls

    Mouse Wheel: Zoom in and out.
    ESC Key: Exit the program.
    Window Close Button: Exit the program.
    For Julia set: 
        x / d - change first parameter by 0.01
        y / s - change second parameter by 0.01
