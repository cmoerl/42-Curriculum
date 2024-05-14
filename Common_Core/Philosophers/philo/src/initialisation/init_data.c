/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:42:36 by csturm            #+#    #+#             */
/*   Updated: 2024/05/14 18:19:13 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static int check_overflow(const char *str)
{
    size_t len;

    len = ft_strlen(str);
    if (len > 10)
        return (1);
    if (len == 10 && ft_strncmp(str, "2147483647", 10) > 0)
        return (1);
    return (0);
}

static char *extract_number(char **argv)
{
    char    *start;
    char    *end;
    char    *num;
    size_t  len;

    while (**argv && ft_iswhitespace(**argv))
        (*argv)++;
    if (**argv == '+')
        (*argv)++;
    start = *argv;
    while (**argv && ft_isdigit(**argv))
        (*argv)++;
    end = *argv;
    len = end - start;
    num = malloc(len + 1);
    if (!num)
        return (error(ERR_MALLOC), NULL);
    ft_memcpy(num, start, len);
    num[len] = '\0';
    return (num);
}

static int check_args(char **argv)
{
    char    *num;
    char    *tmp;

    argv++;
    while (*argv)
    {
        tmp = *argv;
        num = extract_number(&tmp);
        if (!*num || !num)
            return (error(ERR_DIG), 1);
        if (check_overflow(num))
            return (error(ERR_NUM_OF), 1);
        free(num);
        argv++;
    }
    return (0);
}

int    init_data(t_data *data, int argc, char **argv)
{
    if (check_args(argv))
        return (1);
    data->philo_count = ft_atoi_long(argv[1]);
    data->time_to_die = ft_atoi_long(argv[2]);
    data->time_to_eat = ft_atoi_long(argv[3]);
    data->time_to_sleep = ft_atoi_long(argv[4]);
    if (!data->philo_count || !data->time_to_die || !data->time_to_eat || !data->time_to_sleep)
        return (error(ERR_DIG), 1);
    if (argc == 6)
        data->max_meals = ft_atoi_long(argv[5]);
    else
        data->max_meals = -1;
    if (pthread_mutex_init(&data->print, NULL) != 0)
        return (error(ERR_MUTEX), 1);    
    data->philos = NULL;
    data->forks = NULL;
    data->philos = malloc(sizeof(t_philo) * data->philo_count);
    if (!data->philos)
        return (error(ERR_MALLOC), 1);
    data->forks = malloc(sizeof(t_fork) * data->philo_count);
    if (!data->forks)
        return (error(ERR_MALLOC), 1);
    data->start_time = get_start_time();
    if (data->start_time == -1)
        return (error(ERR_TIME), 1);
    data->end = 0;
    return (0);
}
