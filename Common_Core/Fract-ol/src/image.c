/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:34:57 by csturm            #+#    #+#             */
/*   Updated: 2024/02/02 14:23:06 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	put_pxl(t_img *img, int x, int y)
{
	int	position;

	position = y * img->size_l + x * (img->bpp / 8);
	*(unsigned int *)(img->pxl + position) = BLACK;
}

void	put_esc_pxl(t_img *img, int x, int y, int i)
{
	int	colour;
	int	position;

	colour = ((WHITE - BLACK) * (i - 0) / (ITERATIONS - 0) + BLACK);
	position = y * img->size_l + x * (img->bpp / 8);
	*(unsigned int *)(img->pxl + position) = colour;
}
