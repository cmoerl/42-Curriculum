/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:28:58 by csturm            #+#    #+#             */
/*   Updated: 2024/05/06 17:21:42 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int main(int argc, char **argv)
{
    t_data data;

    if (argc != 5 && argc != 6)
        error(ERR_NUM_ARGS);
    init_data(&data, argc, argv);
    if (init_philos(&data))
        return (1);
    if (start_simulation(&data))
        return (1);
    return (0);
}