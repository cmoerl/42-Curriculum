/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:32:07 by csturm            #+#    #+#             */
/*   Updated: 2024/05/14 17:48:17 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int    init_forks(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_count)
    {
        if (pthread_mutex_init(&data->forks[i].mutex, NULL) != 0)
            return (error(ERR_MUTEX), 1);
        data->forks[i].fork_no = i + 1;
        i++;
    }
    return (0);
}