/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:26:06 by csturm            #+#    #+#             */
/*   Updated: 2024/01/30 16:52:34 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../Libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000
# define ITERATIONS 42
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define PURPLE 0xB18AD8

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


t_fractol       *init_fract(/* char *real, char *imaginary, */ char *name);
t_img           *init_img(void *mlx_ptr, int width, int height);
t_hooks         *init_hooks(char *real, char *imgn);
void            malloc_exit_fractol(t_fractol *fractol);
void            put_esc_pxl(t_img *img, int x, int y, int i);
void            put_pxl(t_img *img, int x, int y);
void            render(t_fractol *fractol);

#endif