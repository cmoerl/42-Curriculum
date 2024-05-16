/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:24:49 by csturm            #+#    #+#             */
/*   Updated: 2024/05/16 15:55:03 by csturm           ###   ########.fr       */
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
        philo_sleep(p);
        philo_think(p);
    }
    return (NULL);
}