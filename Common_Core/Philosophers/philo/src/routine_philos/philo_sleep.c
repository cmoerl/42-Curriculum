/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:51:55 by csturm            #+#    #+#             */
/*   Updated: 2024/05/06 21:55:56 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    philo_sleep(t_data *data)
{
    pthread_mutex_lock(&data->philos->mutex);
    print_status(data->philos, "is sleeping");
    pthread_mutex_unlock(&data->philos->mutex);
    usleep(data->time_to_sleep * 1000);
}