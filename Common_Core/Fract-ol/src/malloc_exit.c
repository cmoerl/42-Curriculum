/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:13:58 by csturm            #+#    #+#             */
/*   Updated: 2024/01/22 18:34:45 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fract-ol.h"

static void    free_struct_img(t_img *img)
{
    if (img->img_ptr)
        free(img->img_ptr);
    if (img->pxl)
        free(img->pxl);
    free(img);
}

static void    free_struct_fractol(t_fractol *fractol)
{
    if (fractol->name)
        free(fractol->name);
    if (fractol->mlx_ptr)
        free(fractol->mlx_ptr);
    if (fractol->win_ptr)
        free(fractol->win_ptr);
    if (fractol->img)
        free_struct_img(fractol->img);
    if (fractol->hooks)
        free(fractol->hooks);
    free(fractol);
}

void    malloc_exit_fractol(t_fractol *fractol)
{
    ft_printf("Error: malloc failed\n");
    free_struct_fractol(fractol);
    exit(EXIT_FAILURE);
}