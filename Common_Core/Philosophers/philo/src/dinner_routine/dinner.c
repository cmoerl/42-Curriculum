/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:38:36 by csturm            #+#    #+#             */
/*   Updated: 2024/05/13 16:23:27 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    dinner(t_data *data)
{
    // if (data->philo_count == 1)
    //     one_philo(data);
    if (data->max_meals == 0)
        return ;
    create_threads(data);
    create_monitor(data);
    join_threads(data);
}
