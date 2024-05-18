/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:24:13 by csturm            #+#    #+#             */
/*   Updated: 2024/05/18 13:29:02 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].philo_no = i + 1;
		data->philos[i].prev_meal = 0;
		if (data->philos[i].prev_meal == -1)
			return (error(ERR_TIME, data), 1);
		data->philos[i].meals = 0;
		data->philos[i].data = data;
		data->philos[i].mutex_init = 0;
		if (pthread_mutex_init(&data->philos[i].mutex, NULL) != 0)
			return (error(ERR_MUTEX, data), 1);
		data->philos[i].mutex_init = 1;
		data->forks[i].fork_no = i + 1;
		data->philos[i].left_fork = &data->forks[(i + 1) % data->philo_count];
		data->philos[i].right_fork = &data->forks[i];
		data->philos[i].full = 0;
		i++;
	}
	return (0);
}
