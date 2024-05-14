/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:46:23 by csturm            #+#    #+#             */
/*   Updated: 2024/05/14 17:09:24 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    join_threads(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_count)
    {
        if (pthread_join(data->philos[i].thread_no, NULL) != 0)
            error(ERR_THREAD, data);
        i++;
    }
    if (pthread_join(data->monitor, NULL) != 0)
        error(ERR_THREAD, data);
}
