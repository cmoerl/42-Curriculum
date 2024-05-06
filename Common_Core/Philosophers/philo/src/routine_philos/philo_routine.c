/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:38:36 by csturm            #+#    #+#             */
/*   Updated: 2024/05/06 21:49:35 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    philo_routine(t_data *data)
{
    create_threads(data);
    while (1)
    {
        if (data->end)
            break ;
        philo_sleep(data);
        philo_eat(data);
        philo_think(data);
    }
}
