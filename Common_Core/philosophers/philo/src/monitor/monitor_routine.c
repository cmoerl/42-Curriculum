/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:40:41 by csturm            #+#    #+#             */
/*   Updated: 2024/05/22 16:56:16 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void	check_if_full(t_data *data)
{
	int	i;
	int	full_philos;

	full_philos = 0;
	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&data->philos[i].mutex);
		if (data->philos[i].meals >= data->max_meals)
			full_philos++;
		pthread_mutex_unlock(&data->philos[i].mutex);
		i++;
	}
	if (full_philos == data->philo_count)
	{
		data->end = 1;
		return ;
	}
}

static int	check_if_dead(t_data *data)
{
	int		i;
	long	time;

	i = 0;
	time = get_time(data->start_time);
	if (time == -1)
		return (error(ERR_TIME, data), 1);
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&data->philos[i].mutex);
		if (time - data->philos[i].prev_meal > data->time_to_die
			&& !data->philos[i].full)
		{
			print_status(&data->philos[i], "died");
			data->end = 1;
			pthread_mutex_unlock(&data->philos[i].mutex);
			break ;
		}
		pthread_mutex_unlock(&data->philos[i].mutex);
		i++;
	}
	return (0);
}

void	monitor_routine(t_data *data)
{
	while (!data->end)
	{
		if (data->max_meals != -1)
		{
			check_if_full(data);
			if (data->end)
				break ;
		}
		if (check_if_dead(data))
			break ;
		if (data->end)
			break ;
		usleep(1000);
	}
}
