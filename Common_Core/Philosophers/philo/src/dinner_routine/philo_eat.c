/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:52:45 by csturm            #+#    #+#             */
/*   Updated: 2024/05/16 17:56:56 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static int  hungriest_philo(t_philo *philo)
{
    int i;
    
    i = 0;
    while (i < philo->data->philo_count)
    {
        if (philo->data->philos[i].prev_meal < philo->prev_meal)
            return (0);
        i++;
    }
    return (1);
}

static void   take_forks(t_philo *philo)
{
    while (1)
    {
        if (hungriest_philo(philo) == 1)
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
                if (philo->data->philo_count == 1)
                {
                    pthread_mutex_unlock(&philo->left_fork->mutex);
                    usleep(philo->data->time_to_die * 1000);
                    return ;
                }
                pthread_mutex_lock(&philo->right_fork->mutex);
            }
            print_status(philo, "has taken a fork");
            break ;
        }
        else
            usleep(100);
    }
}

void    philo_eat(t_philo *philo)
{
    take_forks(philo);
    if (philo->data->philo_count == 1)
        return ;
    print_status(philo, "is eating");
    pthread_mutex_lock(&philo->mutex);
    philo->prev_meal = get_time(philo->data->start_time);
    philo->meals++;
    if (philo->meals == philo->data->max_meals)
        philo->full = 1;
    pthread_mutex_unlock(&philo->mutex);
    usleep(philo->data->time_to_eat * 1000);
    pthread_mutex_unlock(&philo->left_fork->mutex);
    pthread_mutex_unlock(&philo->right_fork->mutex);
}