/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:35:40 by csturm            #+#    #+#             */
/*   Updated: 2024/05/10 14:03:02 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    free_data(t_data *data)
{
    int i;

    if (data->philos)
    {
        i = 0;
        while (i < data->philo_count)
        {
            pthread_mutex_destroy(&data->philos[i].mutex);
            i++;
        }
        free(data->philos);
    }
    if (data->forks)
    {
        i = 0;
        while (i < data->philo_count)
        {
            pthread_mutex_destroy(&data->forks[i].mutex);
            i++;
        }
        free(data->forks);
    }
}