/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:51:55 by csturm            #+#    #+#             */
/*   Updated: 2024/05/10 14:37:29 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    philo_sleep(t_philo *philo)
{
    printf("entered philo_sleep\n");
    print_status(philo, "is sleeping");
    usleep(philo->data->time_to_sleep);
}