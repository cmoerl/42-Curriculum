/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:21:49 by csturm            #+#    #+#             */
/*   Updated: 2024/05/16 16:24:35 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    one_philo(t_data *data)
{
    print_status(data->philos, "has taken a fork");
    usleep(data->time_to_die * 1000);
    print_status(data->philos, "died");
}