# Philosophers


## Overview

Philosophers is a project that simulates the classic "Dining Philosophers" problem, focusing on multithreading and synchronization in C. The project involves managing multiple philosophers who alternately eat, think, and sleep while ensuring they do not starve.

## Features

    Simulates the dining philosophers problem with a customizable number of philosophers.
    Uses multithreading to manage philosopher actions.
    Synchronizes access to shared resources using mutexes.
    Logs philosopher actions with timestamps.

## Installation

### Prerequisites

    Unix-like operating system (Linux, macOS).
    GCC compiler.
    Make utility.

### Compilation

To compile the project, clone the repository and run make:

    git clone https://github.com/cmoerl/philosophers.git
    cd philosophers
    make

This will generate an executable named philo.

## Usage

To run the program, use the following command:

    ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

### Parameters

    number_of_philosophers: Number of philosophers and forks.
    time_to_die: Time in milliseconds before a philosopher dies if they don't start eating.
    time_to_eat: Time in milliseconds it takes for a philosopher to eat.
    time_to_sleep: Time in milliseconds a philosopher spends sleeping.
    number_of_times_each_philosopher_must_eat (optional): If specified, the simulation stops when each philosopher has eaten at least this many times. If not specified, the simulation stops when a philosopher dies.

### Example

    ./philo 5 800 200 200

This command starts a simulation with 5 philosophers where each has 800 milliseconds to live without eating, takes 200 milliseconds to eat, and sleeps for 200 milliseconds.

## Logging

The program logs state changes with the following format:

    timestamp_in_ms philosopher_id has taken a fork
    timestamp_in_ms philosopher_id is eating
    timestamp_in_ms philosopher_id is sleeping
    timestamp_in_ms philosopher_id is thinking
    timestamp_in_ms philosopher_id died

    timestamp_in_ms: Current timestamp in milliseconds.
    philosopher_id: The ID of the philosopher (starting from 1).
    