/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:24:49 by csturm            #+#    #+#             */
/*   Updated: 2024/05/22 16:13:38 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	*philo_routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->philo_no % 2 == 0)
		usleep(100);
	while (!p->data->end)
	{
		pthread_mutex_lock(&p->mutex);
		if (p->full)
		{
			pthread_mutex_unlock(&p->mutex);
			usleep (1000);
			continue ;
		}
		pthread_mutex_unlock(&p->mutex);
		philo_eat(p);
		if (p->data->philo_count == 1)
			return (NULL);
		philo_sleep(p);
		philo_think(p);
	}
	return (NULL);
}
