/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:21:30 by csturm            #+#    #+#             */
/*   Updated: 2024/02/01 13:44:10 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fract-ol.h"

void	malloc_exit_fractol(t_fractol *fractol)
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

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_ptr, fractol->img->img_ptr);
	mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
	mlx_destroy_display(fractol->mlx_ptr);
	malloc_exit_fractol(fractol);
	return (0);
}

int	key_handler(int keycode, t_fractol *fractol)
{
	if (keycode == XK_Escape)
		close_handler(fractol);
	else if (keycode == XK_Left)
		fractol->hooks->shift_x -= (0.2 * fractol->hooks->zoom);
	else if (keycode == XK_Right)
		fractol->hooks->shift_x += (0.2 * fractol->hooks->zoom);
	else if (keycode == XK_Up)
		fractol->hooks->shift_y += (0.2 * fractol->hooks->zoom);
	else if (keycode == XK_Down)
		fractol->hooks->shift_y -= (0.2 * fractol->hooks->zoom);
	render(fractol);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 5)
		fractol->hooks->zoom *= 1.1;
	else if (button == 4)
		fractol->hooks->zoom *= 0.9;
	render(fractol);
	return (0);
}
