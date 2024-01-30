/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:26:39 by csturm            #+#    #+#             */
/*   Updated: 2024/01/30 16:38:06 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fract-ol.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    t_fractol *fractol;
    
    if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
        fractol = init_fract(/* NULL, NULL, */ argv[1]);
    // else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
    //     fractol = init_fract(argv[2], argv[3], argv[1]);
    else
    {
        ft_printf("Available fractals: mandelbrot, julia\n");
        exit(EXIT_FAILURE);
    }
    render(fractol);
    // mlx_hook(fractol->win, 2, 0, key_press, fractol);
    // mlx_hook(fractol->win, 4, 0, mouse_press, fractol);
    // mlx_hook(fractol->win, 6, 0, mouse_move, fractol);
    // mlx_hook(fractol->win, 17, 0, close_window, fractol);
    mlx_loop(fractol->mlx_ptr);
    return (0);
}
