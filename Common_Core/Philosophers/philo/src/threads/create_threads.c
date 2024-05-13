/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:42:54 by csturm            #+#    #+#             */
/*   Updated: 2024/05/13 15:29:47 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    create_threads(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_count)
    {
        printf("create_threads philo_no: %d\n", data->philos[i].philo_no);
        if (pthread_create(&data->philos[i].thread_no, NULL, philo_routine, &data->philos[i]) != 0)
            error(ERR_THREAD, data);
        i++;
    }
}