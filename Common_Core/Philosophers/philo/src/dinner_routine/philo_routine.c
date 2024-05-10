/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:24:49 by csturm            #+#    #+#             */
/*   Updated: 2024/05/10 14:33:59 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	*philo_routine(void *philo)
{
    t_philo	*p;

    printf("philo %d entered philo_routine\n", ((t_philo *)philo)->philo_no);
    p = (t_philo *)philo;
    // wait_for_threads(p->data); /* necessary? */
    while (!p->data->end)
    {
        philo_eat(p);
        philo_sleep(p);
        philo_think(p);
    }
    return (NULL);
}