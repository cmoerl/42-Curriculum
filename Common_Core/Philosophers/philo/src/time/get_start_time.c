/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:54:15 by csturm            #+#    #+#             */
/*   Updated: 2024/05/13 15:54:21 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

long long get_start_time(void)
{
    struct timeval start_time;
    long long       milliseconds;

    gettimeofday(&start_time, NULL);
    milliseconds = ((long long)start_time.tv_sec * 1000) + ((long long)start_time.tv_usec / 1000);
    return (milliseconds);
}