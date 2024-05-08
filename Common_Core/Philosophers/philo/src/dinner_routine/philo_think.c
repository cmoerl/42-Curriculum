/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:52:31 by csturm            #+#    #+#             */
/*   Updated: 2024/05/06 22:55:55 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    philo_think(t_data *data)
{
    pthread_mutex_lock(&data->philos->mutex);
    print_status(data->philos, "is thinking");
    pthread_mutex_unlock(&data->philos->mutex);
}