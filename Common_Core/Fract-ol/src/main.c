/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:26:39 by csturm            #+#    #+#             */
/*   Updated: 2024/01/23 15:33:13 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fract-ol.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    t_fractol *fractol;
    
    if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
        fractol = init_mandelbrot();
    else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
        fractol = init_julia(argv[2], argv[3]);
    else
    {
        ft_printf("Usage: ./fractol [fractal]\n");
        ft_printf("Available fractals: mandelbrot, julia, burningship\n");
        exit(EXIT_FAILURE);
    }
    render(fractol);
    mlx_hook(fractol->win, 2, 0, key_press, fractol);
    mlx_hook(fractol->win, 4, 0, mouse_press, fractol);
    mlx_hook(fractol->win, 6, 0, mouse_move, fractol);
    mlx_hook(fractol->win, 17, 0, close_window, fractol);
    mlx_loop(fractol->mlx);
    return (0);
}
