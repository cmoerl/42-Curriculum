/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:26:39 by csturm            #+#    #+#             */
/*   Updated: 2024/02/02 13:41:45 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

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
	mlx_hook(fractol->win_ptr, ButtonPress, ButtonPressMask,
		mouse_handler, fractol);
	mlx_hook(fractol->win_ptr, DestroyNotify, StructureNotifyMask,
		close_handler, fractol);
	mlx_loop(fractol->mlx_ptr);
	return (0);
}
