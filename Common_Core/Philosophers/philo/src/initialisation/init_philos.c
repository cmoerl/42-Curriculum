/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:24:13 by csturm            #+#    #+#             */
/*   Updated: 2024/05/14 17:50:25 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int    init_philos(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_count)
    {
        data->philos[i].philo_no = i + 1;
        data->philos[i].prev_meal = 0;
        if (data->philos[i].prev_meal == -1)
            return (error(ERR_TIME), 1);
        data->philos[i].meals = 0;
        data->philos[i].data = data;
        if (pthread_mutex_init(&data->philos[i].mutex, NULL) != 0)
            return (error(ERR_MUTEX), 1);
        if (pthread_mutex_init(&data->forks[i].mutex, NULL) != 0)
            return (error(ERR_MUTEX), 1);
        data->forks[i].fork_no = i + 1;
        data->philos[i].left_fork = &data->forks[(i + 1) % data->philo_count];
        data->philos[i].right_fork = &data->forks[i];
        data->philos[i].full = 0;
        i++;
    }
    return (0);
}
