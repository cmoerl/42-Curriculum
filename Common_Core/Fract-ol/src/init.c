/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:44:36 by csturm            #+#    #+#             */
/*   Updated: 2024/02/02 13:41:41 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

t_img	*init_img(void *mlx_ptr, int width, int height)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img_ptr = mlx_new_image(mlx_ptr, width, height);
	if (!img->img_ptr)
		return (NULL);
	img->pxl = mlx_get_data_addr(img->img_ptr,
			&img->bpp, &img->size_l, &img->endian);
	if (!img->pxl)
		return (NULL);
	return (img);
}

t_hooks	*init_hooks(char *real, char *imaginary)
{
	t_hooks	*hooks;
	double	real_num;
	double	imaginary_num;

	if (real != NULL && imaginary != NULL)
	{
		real_num = ft_strtod(real);
		imaginary_num = ft_strtod(imaginary);
	}
	else
	{
		real_num = 0.0;
		imaginary_num = 0.0;
	}
	hooks = malloc(sizeof(t_hooks));
	if (!hooks)
		return (NULL);
	hooks->shift_x = 0.0;
	hooks->shift_y = 0.0;
	hooks->zoom = 1.0;
	hooks->julia_x = real_num;
	hooks->julia_y = imaginary_num;
	return (hooks);
}

void	protect_ptr(void *ptr, t_fractol *fractol)
{
	if (!ptr)
	{
		if (fractol->win_ptr)
			mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
		if (fractol->mlx_ptr)
			mlx_destroy_display(fractol->mlx_ptr);
		malloc_exit_fractol(fractol);
	}
}

t_fractol	*init_fract(char *real, char *imaginary, char *name)
{
	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	protect_ptr(fractol, fractol);
	fractol->name = name;
	fractol->mlx_ptr = mlx_init();
	protect_ptr(fractol->mlx_ptr, fractol);
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr,
			WIDTH, HEIGHT, fractol->name);
	protect_ptr(fractol->win_ptr, fractol);
	fractol->img = init_img(fractol->mlx_ptr, WIDTH, HEIGHT);
	protect_ptr(fractol->img, fractol);
	fractol->hooks = init_hooks(real, imaginary);
	protect_ptr(fractol->hooks, fractol);
	return (fractol);
}
