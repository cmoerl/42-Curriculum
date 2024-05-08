/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:42:54 by csturm            #+#    #+#             */
/*   Updated: 2024/05/08 17:24:20 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    create_threads(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_count)
    {
        if (pthread_create(&data->philos[i].thread_no, NULL, /* insert function */, &data->philos[i]) != 0)
        {
            free_data(data);
            error(ERR_THREAD);
        }
        i++;
    }
    i = 0;
    while (i < data->philo_count)
    {
        if (pthread_join(data->philos[i].thread_no, NULL) != 0)
        {
            free_data(data);
            error(ERR_THREAD);
        }
        i++;
    }
}