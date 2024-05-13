/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:23:55 by csturm            #+#    #+#             */
/*   Updated: 2024/05/13 16:26:02 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    create_monitor(t_data *data)
{
    if (pthread_create(&data->monitor, NULL, (void *)monitor_routine, data) != 0)
        error(ERR_THREAD, data);
}