/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:52:45 by csturm            #+#    #+#             */
/*   Updated: 2024/05/10 14:53:55 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static void   take_forks(t_philo *philo)
{
    printf("entered take_forks\n");
    if (philo->philo_no % 2 == 0)
    {
        printf("philo_no is even, should take fork %d and fork %d\n", philo->left_fork->fork_no, philo->right_fork->fork_no);
        pthread_mutex_lock(&philo->right_fork->mutex);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(&philo->left_fork->mutex);
    }
    else
    {
        printf("philo_no is odd, should take fork %d and fork %d\n", philo->right_fork->fork_no, philo->left_fork->fork_no);
        pthread_mutex_lock(&philo->left_fork->mutex);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(&philo->right_fork->mutex);
    }
    print_status(philo, "has taken a fork");
}

void    philo_eat(t_philo *philo)
{
    printf("entered philo_eat\n");
    take_forks(philo);
    print_status(philo, "is eating");
    usleep(philo->data->time_to_eat);
    philo->meals++;
    if (philo->meals == philo->data->max_meals)
        philo->full = 1;
    pthread_mutex_unlock(&philo->left_fork->mutex);
    pthread_mutex_unlock(&philo->right_fork->mutex);
}