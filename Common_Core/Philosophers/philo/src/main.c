/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:28:58 by csturm            #+#    #+#             */
/*   Updated: 2024/05/18 13:36:20 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){0};
	if (argc != 5 && argc != 6)
		return (error(ERR_NUM_ARGS, NULL), 1);
	if (init_data(&data, argc, argv))
		return (free_data(&data), 1);
	if (init_forks(&data))
		return (free_data(&data), 1);
	if (init_philos(&data))
		return (free_data(&data), 1);
	dinner(&data);
	free_data(&data);
	return (0);
}
