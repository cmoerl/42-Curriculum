/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:26:39 by csturm            #+#    #+#             */
/*   Updated: 2024/01/31 17:34:32 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fract-ol.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_fractol *fractol;
    
    if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
        fractol = init_fract(NULL, NULL, argv[1]);
    else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
        fractol = init_fract(argv[2], argv[3], argv[1]);
    else
    {
        ft_printf("Available fractals: mandelbrot, julia\n");
        exit(EXIT_FAILURE);
    }
    render(fractol);
    mlx_hook(fractol->win_ptr, KeyPress, KeyPressMask, key_handler, fractol);  
    mlx_hook(fractol->win_ptr, ButtonPress, ButtonPressMask, mouse_handler, fractol);
    mlx_hook(fractol->win_ptr, DestroyNotify, StructureNotifyMask, close_handler, fractol);
    // mlx_hook(fractol->win_ptr, MotionNotify, PointerMotionMask, julia_track, fractol);
    mlx_loop(fractol->mlx_ptr);
    return (0);
}
