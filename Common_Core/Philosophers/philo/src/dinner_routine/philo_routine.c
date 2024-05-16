/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:24:49 by csturm            #+#    #+#             */
/*   Updated: 2024/05/16 18:01:12 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	*philo_routine(void *philo)
{
    t_philo	*p;

    p = (t_philo *)philo;
    while (!p->data->end)
    {
        if (p->full)
            continue ;
        philo_eat(p);
        if (p->data->philo_count == 1)
            return (NULL);
        philo_sleep(p);
        philo_think(p);
    }
    return (NULL);
}