/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:52:45 by csturm            #+#    #+#             */
/*   Updated: 2024/05/06 21:55:39 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    philo_eat(t_data *data)
{
    pthread_mutex_lock(&data->philos->mutex);
    print_status(data->philos, "is eating");
    pthread_mutex_unlock(&data->philos->mutex);
    usleep(data->time_to_eat * 1000);
    data->philos->meals++;
    if (data->philos->meals == data->max_meals)
        data->philos->full = 1;
}