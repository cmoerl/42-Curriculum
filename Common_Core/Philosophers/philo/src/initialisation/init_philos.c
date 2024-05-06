/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:24:13 by csturm            #+#    #+#             */
/*   Updated: 2024/05/06 17:29:52 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    init_philos(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_count)
    {
        data->philos[i].philo_no = i + 1;
        data->philos[i].prev_meal = get_time();
        data->philos[i].meals = 0;
        data->philos[i].data = data;
        pthread_mutex_init(&data->philos[i]., NULL);
        i++;
    }
}