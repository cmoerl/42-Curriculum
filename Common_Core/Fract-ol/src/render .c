/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render .c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:37:03 by csturm            #+#    #+#             */
/*   Updated: 2024/01/23 18:23:31 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fract-ol.h"

void    render_mandelbrot(double x_scaled, double y_scaled, t_fractol *fractol)
{
    t_complex   z;
    t_complex   c;
    double      sum;
    int         i;

    z.real = 0.0;
    z.imgn = 0.0;
    c.real = 4 * (double)x / WIDTH - 2;
    c.imgn = 2 - (double)y / HEIGHT * 4;
    i = 0;
    while (i < 42)
    {
        sum += z.real * z.real - z.imgn * z.imgn + c.real;
        if (sum > 4)
            break ;
        i++;
    }
    if (i != 42)
        put_esc_pxl(fractol->img, z, c, i);
    else
        put_pxl(fractol->img, z, c, i);
}

void    iterate_map(t_fractol *fractol)
{
    double  x_scaled;
    double  y_scaled;
    int     x;
    int     y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            if (ft_strncmp(fractol->name,  "mandelbrot", 10) == 0)
                render_mandelbrot(fractol);
            else if (ft_strncmp(fractol->name, "julia", 5) == 0)
                render_julia(fractol);
            x++;
        }
        y++;
    }

}

void render(t_fractol *fractol)
{
    iterate_map(fractol);
    mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr, fractol->img->img_ptr, 0, 0);
}