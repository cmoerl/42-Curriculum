/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:26:39 by csturm            #+#    #+#             */
/*   Updated: 2024/02/08 16:28:17 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"
#include <stdio.h>

static void	wait_for_events(t_fractol *fractol)
{
	mlx_hook(fractol->win_ptr, KeyPress, KeyPressMask, key_handler, fractol);
	mlx_hook(fractol->win_ptr, ButtonPress, ButtonPressMask,
		mouse_handler, fractol);
	mlx_hook(fractol->win_ptr, DestroyNotify, StructureNotifyMask,
		close_handler, fractol);
	mlx_loop(fractol->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		fractol = init_fract(NULL, NULL, argv[1]);
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 6))
	{
		if (!check_args(argv[2], argv[3]))
		{
			ft_printf("Invalid julia arguments\n");
			exit(EXIT_FAILURE);
		}
		fractol = init_fract(argv[2], argv[3], argv[1]);
	}
	else
	{
		ft_printf("Available fractals: mandelbrot, julia\n");
		ft_printf("The julia set is given coordinates as arguments\n");
		exit(EXIT_FAILURE);
	}
	render(fractol);
	wait_for_events(fractol);
	return (0);
}
