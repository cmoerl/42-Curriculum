/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:26:39 by csturm            #+#    #+#             */
/*   Updated: 2024/01/21 18:38:47 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fract-ol.h"

int main(int argc, char **argv)
{
    t_fractol *fractol;

    if (argc != 2)
    {
        ft_putstr("Usage: ./fractol [fractal]\n");
        ft_putstr("Available fractals: mandelbrot, julia, burningship\n");
        return (0);
    }
    fractol = init_fractol(argv[1]);
    if (!fractol)
    {
        ft_putstr("Usage: ./fractol [fractal]\n");
        ft_putstr("Available fractals: mandelbrot, julia, burningship\n");
        return (0);
    }
    mlx_hook(fractol->win, 2, 0, key_press, fractol);
    mlx_hook(fractol->win, 4, 0, mouse_press, fractol);
    mlx_hook(fractol->win, 6, 0, mouse_move, fractol);
    mlx_hook(fractol->win, 17, 0, close_window, fractol);
    mlx_loop(fractol->mlx);
    return (0);
}