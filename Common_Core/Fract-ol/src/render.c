/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:37:03 by csturm            #+#    #+#             */
/*   Updated: 2024/02/02 13:41:48 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

t_complex	mandelbrot_formula(t_complex z, t_complex c)
{
	t_complex	result;

	result.real = z.real * z.real - z.imgn * z.imgn + c.real;
	result.imgn = 2 * z.real * z.imgn + c.imgn;
	return (result);
}

double	scale(double value, int real)
{
	if (real)
		return ((2 - (-2)) * (value - 0) / (WIDTH - 0) + (-2));
	else
		return ((-2 - 2) * (value - 0) / (HEIGHT - 0) + 2);
}

void	render_mandelbrot(double x, double y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	double		sum;
	int			i;

	z.real = 0.0;
	z.imgn = 0.0;
	c.real = (scale(x, 1) * fractol->hooks->zoom) + fractol->hooks->shift_x;
	c.imgn = (scale(y, 0) * fractol->hooks->zoom) + fractol->hooks->shift_y;
	i = 0;
	while (i < ITERATIONS)
	{
		z = mandelbrot_formula(z, c);
		sum = z.real * z.real + z.imgn * z.imgn;
		if (sum > 4)
			break ;
		i++;
	}
	if (i == ITERATIONS)
		put_pxl(fractol->img, (int)x, (int)y);
	else
		put_esc_pxl(fractol->img, (int)x, (int)y, i);
}

void	render_julia(double x, double y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	double		sum;
	int			i;

	z.real = (scale(x, 1) * fractol->hooks->zoom) + fractol->hooks->shift_x;
	z.imgn = (scale(y, 0) * fractol->hooks->zoom) + fractol->hooks->shift_y;
	c.real = fractol->hooks->julia_x;
	c.imgn = fractol->hooks->julia_y;
	i = 0;
	while (i < ITERATIONS)
	{
		z = mandelbrot_formula(z, c);
		sum = z.real * z.real + z.imgn * z.imgn;
		if (sum > 4)
			break ;
		i++;
	}
	if (i == ITERATIONS)
		put_pxl(fractol->img, (int)x, (int)y);
	else
		put_esc_pxl(fractol->img, (int)x, (int)y, i);
}

void	render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (ft_strncmp(fractol->name, "mandelbrot", 10) == 0)
				render_mandelbrot(x, y, fractol);
			else if (ft_strncmp(fractol->name, "julia", 5) == 0)
				render_julia(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img->img_ptr, 0, 0);
}
