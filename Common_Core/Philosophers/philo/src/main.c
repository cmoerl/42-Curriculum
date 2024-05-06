/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:28:58 by csturm            #+#    #+#             */
/*   Updated: 2024/05/06 21:50:36 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int main(int argc, char **argv)
{
    t_data data;

    if (argc != 5 && argc != 6)
        error(ERR_NUM_ARGS);
    init_data(&data, argc, argv);
    init_forks(&data);
    init_philos(&data);
    philo_routine(&data);
    monitor_routine(&data);
    free_data(&data);
    return (0);
}
