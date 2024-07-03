/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:26:06 by csturm            #+#    #+#             */
/*   Updated: 2024/02/05 14:41:24 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../Libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

# define WIDTH 1000
# define HEIGHT 1000
# define ITERATIONS 200
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define PURPLE 0xB18AD8
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define BLUE 0x0000FF

typedef struct s_complex
{
	double	real;
	double	imgn;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pxl;
	int		bpp;
	int		size_l;
	int		endian;
}	t_img;

typedef struct s_hooks
{
	double	esc;
	int		it_def;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_hooks;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	t_hooks	*hooks;
}	t_fractol;

t_fractol	*init_fract(char *real, char *imaginary, char *name);
t_img		*init_img(void *mlx_ptr, int width, int height);
t_hooks		*init_hooks(char *real, char *imgn);
void		malloc_exit_fractol(t_fractol *fractol);
void		put_esc_pxl(t_img *img, int x, int y, int i);
void		put_pxl(t_img *img, int x, int y);
void		render(t_fractol *fractol);
int			close_handler(t_fractol *fractol);
int			key_handler(int keycode, t_fractol *fractol);
int			mouse_handler(int button, int x, int y, t_fractol *fractol);
int			check_args(char *real, char *imaginary);

#endif