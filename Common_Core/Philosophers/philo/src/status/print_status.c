/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:24:43 by csturm            #+#    #+#             */
/*   Updated: 2024/05/13 15:57:12 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void    print_status(t_philo *philo, char *status)
{
    pthread_mutex_lock(&philo->data->print);
    if (philo->data->end)
    {
        pthread_mutex_unlock(&philo->data->print);
        return ;
    }
    printf("%lld %d %s\n", get_time(philo->data->start_time), philo->philo_no, status);
    pthread_mutex_unlock(&philo->data->print);
}