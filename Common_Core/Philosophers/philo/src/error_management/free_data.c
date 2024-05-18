/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:35:40 by csturm            #+#    #+#             */
/*   Updated: 2024/05/18 13:55:39 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	destroy_and_free(t_data *data, int philo)
{
	int	i;

	while (i < data->philo_count)
	{
		if (philo && data->philos[i].mutex_init)
			pthread_mutex_destroy(&data->philos[i].mutex);
		else if (!philo && data->forks[i].mutex_init)
			pthread_mutex_destroy(&data->forks[i].mutex);
		i++;
	}
	if (philo)
		free(data->philos);
	else
		free(data->forks);
}

void	free_data(t_data *data)
{
	if (data)
	{
		if (data->philos)
		{
			destroy_and_free(data, 1);
		}
		if (data->forks)
		{
			destroy_and_free(data, 0);
		}
		if (data->print_init)
			pthread_mutex_destroy(&data->print);
	}
}
