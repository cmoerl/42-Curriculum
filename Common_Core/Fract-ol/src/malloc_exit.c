/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:13:58 by csturm            #+#    #+#             */
/*   Updated: 2024/01/31 16:40:52 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fract-ol.h"

void    malloc_exit_fractol(t_fractol *fractol)
{
    if (fractol->mlx_ptr)
        free(fractol->mlx_ptr);
    if (fractol->img)
        free (fractol->img);
    if (fractol->hooks)
        free(fractol->hooks);
    free(fractol);
    exit(EXIT_SUCCESS);
}