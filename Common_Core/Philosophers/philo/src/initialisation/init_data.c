/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:42:36 by csturm            #+#    #+#             */
/*   Updated: 2024/05/06 21:47:54 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static int check_overflow(const char *str)
{
    if (ft_strlen(str) > 10)
        return (1);
    if (ft_strlen(str) == 10 && ft_strncmp(str, "9223372036854775807", 20) > 0)
        return (1);
    return (0);
}

static void check_args(int argc, char **argv)
{
    while (*argv)
    {
        if (!ft_isdigit(**argv))
            error(ERR_DIG);
        if (check_overflow(*argv))
            error(ERR_NUM_OF);
        argv++;
    }
}

void    init_data(t_data *data, int argc, char **argv)
{
    check_args(argc, argv);
    data->philo_count = ft_atoi_long(argv[1]);
    data->time_to_die = ft_atoi_long(argv[2]);
    data->time_to_eat = ft_atoi_long(argv[3]);
    data->time_to_sleep = ft_atoi_long(argv[4]);
    if (argc == 6)
        data->max_meals = ft_atoi_long(argv[5]);
    else
        data->max_meals = -1;
    data->philos = NULL;
    data->forks = NULL;
    data->philos = malloc(sizeof(t_philo) * data->philo_count);
    if (!data->philos)
        error(ERR_MALLOC);
    data->forks = malloc(sizeof(t_fork) * data->philo_count);
    if (!data->forks)
    {
        free(data->philos);
        error(ERR_MALLOC);
    }
    data->start_time = get_time();
    if (data->start_time == -1)
    {
        free(data->philos);
        free(data->forks);
        error(ERR_TIME);
    }
    data->end = 0;
}
