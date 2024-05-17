/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:42:54 by csturm            #+#    #+#             */
/*   Updated: 2024/05/17 17:18:57 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int    create_threads(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_count)
    {
        if (pthread_create(&data->philos[i].thread_no, NULL, philo_routine, &data->philos[i]) != 0)
            return (error(ERR_THREAD, data), 1);
        i++;
    }
    return (0);
}