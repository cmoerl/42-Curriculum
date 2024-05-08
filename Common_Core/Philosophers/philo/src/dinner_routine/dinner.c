/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:38:36 by csturm            #+#    #+#             */
/*   Updated: 2024/05/08 17:16:18 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    dinner(t_data *data)
{
    if (data->philo_count == 1)
    {
        /* error */
    }
    if (data->max_meals == 0)
        return ;
    create_threads(data);
    create_monitor(data);
    while (1)
    {
        if (data->end)
            break ;
        philo_sleep(data);
        philo_eat(data);
        philo_think(data);
    }
}
