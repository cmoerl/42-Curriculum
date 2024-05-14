/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:40:41 by csturm            #+#    #+#             */
/*   Updated: 2024/05/14 17:03:02 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void    check_if_full(t_data *data)
{
    int i;
    int full_philos;

    full_philos = 0;
    i = 0;
    while (i < data->philo_count)
    {
        if (data->philos[i].meals >= data->max_meals)
            full_philos++;
        i++;
    }
    if (full_philos == data->philo_count)
    {
        data->end = 1;
        return ;
    }
}

static void    check_if_dead(t_data *data)
{
    int i;
    long time;

    i = 0;
    time = get_time(data->start_time);
    if (time == -1)
        error(ERR_TIME, data);
    while (i < data->philo_count)
    {
        if (time - data->philos[i].prev_meal > data->time_to_die && !data->philos[i].full)
        {
            print_status(&data->philos[i], "died");
            data->end = 1;
            break ;
        }
        i++;
    }
}

void    monitor_routine(t_data *data)
{
    /* wait until all threads are running? */
    while (!data->end)
    {
        if (data->max_meals != -1)
        {
            check_if_full(data);
            if (data->end)
                break ;
        }
        check_if_dead(data);
        if (data->end)
            break ;
        usleep(1000);
    }
}