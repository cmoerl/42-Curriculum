/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:52:45 by csturm            #+#    #+#             */
/*   Updated: 2024/05/16 16:25:51 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void   take_forks(t_philo *philo)
{
    if (philo->philo_no % 2 == 0)
    {
        pthread_mutex_lock(&philo->right_fork->mutex);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(&philo->left_fork->mutex);
    }
    else
    {
        pthread_mutex_lock(&philo->left_fork->mutex);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(&philo->right_fork->mutex);
    }
    print_status(philo, "has taken a fork");
}

void    philo_eat(t_philo *philo)
{
    take_forks(philo);
    print_status(philo, "is eating");
    pthread_mutex_lock(&philo->mutex);
    philo->prev_meal = get_time(philo->data->start_time) + philo->data->time_to_eat;
    philo->meals++;
    if (philo->meals == philo->data->max_meals)
        philo->full = 1;
    pthread_mutex_unlock(&philo->mutex);
    usleep(philo->data->time_to_eat * 1000);
    pthread_mutex_unlock(&philo->left_fork->mutex);
    pthread_mutex_unlock(&philo->right_fork->mutex);
}