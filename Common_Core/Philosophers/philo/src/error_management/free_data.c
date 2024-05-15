/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:35:40 by csturm            #+#    #+#             */
/*   Updated: 2024/05/15 17:26:20 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    free_data(t_data *data)
{
    int i;

    if (data)
    {
        if (data->philos)
        {
            i = 0;
            while (i < data->philo_count)
            {
                if (data->philos[i].mutex_init)
                    pthread_mutex_destroy(&data->forks[i].mutex);
                i++;
            }
            free(data->philos);
        }
        if (data->forks)
        {
            i = 0;
            while (i < data->philo_count)
            {
                if (data->forks[i].mutex_init)
                    pthread_mutex_destroy(&data->forks[i].mutex);
                i++;
            }
            free(data->forks);
        }
        if (data->print_init)
            pthread_mutex_destroy(&data->print);
    }
}
