/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:03:05 by csturm            #+#    #+#             */
/*   Updated: 2024/06/19 17:03:29 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	render(t_scene *scene)
{
    t_ray	ray;
    t_color	color;
    int		x;
    int		y;

    y = 0;
    while (y < scene->res.y)
    {
        x = 0;
        while (x < scene->res.x)
        {
            ray = get_ray(scene, x, y);
            color = trace_ray(scene, ray, 0);
            my_mlx_pixel_put(scene, x, y, color);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(scene->mlx, scene->win, scene->img, 0, 0);
}