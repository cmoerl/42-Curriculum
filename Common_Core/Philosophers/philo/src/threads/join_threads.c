/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:46:23 by csturm            #+#    #+#             */
/*   Updated: 2024/05/17 17:19:06 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    join_threads(t_data *data)
{
    int i;
    int err;

    i = 0;
    err = 0;
    while (i < data->philo_count)
    {
        if (pthread_join(data->philos[i].thread_no, NULL) != 0)
            err = 1;
        i++;
    }
    if (pthread_join(data->monitor, NULL) != 0)
        err = 1;
    if (err)
        error(ERR_THREAD, data);
}
