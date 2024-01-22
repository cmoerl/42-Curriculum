/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:26:06 by csturm            #+#    #+#             */
/*   Updated: 2024/01/22 18:35:07 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../Libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct	s_complex
{
    double		real;
    double		imgn;
}				t_complex;

typedef struct    s_img
{
    void		*img_ptr;
    char        *pxl;
    int			bpp;
    int			size_l;
    int			endian;
}				t_img;

typedef struct  s_hooks
{
    double      esc;
    int         it_def;
    double      shift_x;
    double      shift_y;
    double      zoom;
    double      julia_x;
    double      julia_y;
}               t_hooks;

typedef struct  s_fractol
{
    char        *name;
    void        *mlx_ptr;
    void        *win_ptr;
    t_img       *img;
    t_hooks     *hooks;
}            t_fractol;


t_fractol       *init_mandelbrot(void);
t_fractol       *init_julia(char *real, char *imgn);
t_img           *init_img(t_fractol *fractol);
t_hooks         *init_hooks(char *real, char *imgn);
void            malloc_exit_fractol(t_fractol *fractol);


#endif