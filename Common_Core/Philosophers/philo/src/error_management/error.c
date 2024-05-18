/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:31:57 by csturm            #+#    #+#             */
/*   Updated: 2024/05/18 13:22:44 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	error(char *msg, t_data *data)
{
	if (data)
	{
		pthread_mutex_lock(&data->print);
		printf("Error: %s\n", msg);
		pthread_mutex_unlock(&data->print);
	}
	else
		printf("Error: %s\n", msg);
}
