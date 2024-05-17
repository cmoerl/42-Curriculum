/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:23:55 by csturm            #+#    #+#             */
/*   Updated: 2024/05/17 17:18:26 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int    create_monitor(t_data *data)
{
    if (pthread_create(&data->monitor, NULL, (void *)monitor_routine, data) != 0)
        return (error(ERR_THREAD, data), 1);
    return (0);
}