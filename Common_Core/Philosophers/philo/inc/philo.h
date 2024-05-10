/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:11:15 by csturm            #+#    #+#             */
/*   Updated: 2024/05/10 14:52:45 by csturm           ###   ########.fr       */
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
#define ERR_NUM_OF "Invalid number, must be between 0 and 2147483647"
#define ERR_MALLOC "Malloc failed"
#define ERR_TIME "Failed to get time"
#define ERR_MUTEX "Failed to init mutex"
#define ERR_THREAD "Failed to create thread"

typedef struct s_data t_data;

/* add flag to show if mutex has been initialised --> for free_data */
typedef struct s_fork
{
    pthread_mutex_t mutex;
    int             fork_no;
} t_fork;

/* add flag to show if mutex has been initialised --> for free_data */
typedef struct s_philo
{
    int             philo_no;
    t_fork          *left_fork;
    t_fork          *right_fork;
    int             meals;
    long long       prev_meal;
    int             full;
    pthread_t       thread_no;
    pthread_mutex_t mutex;
    t_data          *data;
} t_philo;

typedef struct s_data
{
    long                philo_count;
    long                time_to_die;
    long                time_to_eat;
    long                time_to_sleep;
    long                max_meals;
    t_philo             *philos;
    t_fork              *forks;
    int                 start_time;
    pthread_mutex_t     print;
    int                 end;
} t_data;

/* error management */

void        error(char *msg, t_data *data);
void        free_data(t_data *data);

/* initialisation */

void        init_data(t_data *data, int argc, char **argv);
void        init_forks(t_data *data);
void        init_philos(t_data *data);

/* threads */

void        create_threads(t_data *data);
void        join_threads(t_data *data);

/* time */

long long   get_time(void);

/* mini library */

long	    ft_atoi_long(const char *nptr);
int         ft_isdigit(int c);
size_t	    ft_strlen(const char *s);
int	        ft_strncmp(const char *s1, const char *s2, size_t n);
int	        ft_iswhitespace(int c);
void	    *ft_memcpy(void *dest, const void *src, size_t n);

/* monitor */

/* void        monitor_routine(t_data *data); */

/* status */

void        print_status(t_philo *philo, char *status);

/* dinner routine */

void        dinner(t_data *data);
void	    *philo_routine(void *philo);
void        philo_sleep(t_philo *philo);
void        philo_eat(t_philo *philo);
void        philo_think(t_philo *philo);

#endif