/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:08:16 by csturm            #+#    #+#             */
/*   Updated: 2024/05/18 13:39:07 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

long long	get_time(long long start_time)
{
	struct timeval	current_time;
	long long		milliseconds;

	gettimeofday(&current_time, NULL);
	milliseconds = ((long long)current_time.tv_sec * 1000)
		+ ((long long)current_time.tv_usec / 1000);
	return (milliseconds - start_time);
}
