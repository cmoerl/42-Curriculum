/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:38:36 by csturm            #+#    #+#             */
/*   Updated: 2024/05/16 16:43:51 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    dinner(t_data *data)
{
    if (data->max_meals == 0)
        return ;
    if (create_threads(data))
        data->end = 1;
    if (create_monitor(data))
        data->end = 1;
    join_threads(data);
}
