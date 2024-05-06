/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:11:15 by csturm            #+#    #+#             */
/*   Updated: 2024/05/06 17:22:27 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>

#define ERR_NUM_ARGS "Invalid number of arguments"
#define ERR_DIG "Invalid argument, must be a positive number"
#define ERR_NUM_OF "Invalid number, must be between 0 and 9223372036854775807"
#define ERR_MALLOC "Malloc failed"

typedef struct s_data t_data;

typedef struct s_fork
{
    pthread_mutex_t mutex;
    int             fork_no;
} t_fork;

typedef struct s_philo
{
    int         philo_no;
    t_fork      left_fork;
    t_fork      right_fork;
    int         meals;
    int         prev_meal;
    pthread_t   thread_no;
    t_data      *data;
} t_philo;

typedef struct s_data
{
    long         philo_count;
    long         time_to_die;
    long         time_to_eat;
    long         time_to_sleep;
    long         max_meals;
    t_philo     *philos;
    t_fork      *forks;
    int         start_time;
} t_data;

/* error management */

void    error(char *msg);

/* initialisation */

void    init_data(t_data *data, int argc, char **argv);

/* mini library */

long	ft_atoi_long(const char *nptr);
int     ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);

#endif