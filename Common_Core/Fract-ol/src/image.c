/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:34:57 by csturm            #+#    #+#             */
/*   Updated: 2024/02/01 13:38:26 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fract-ol.h"

void    put_pxl(t_img *img, int x, int y)
{
    int position;
    
    position = y * img->size_l + x * (img->bpp / 8);
    *(unsigned int *)(img->pxl + position) = WHITE;
}

void    put_esc_pxl(t_img *img, int x, int y, int i)
{
    int colour;
    int position;
    
    colour = ((YELLOW - RED) * (i - 0) / (ITERATIONS - 0) + RED);
    position = y * img->size_l + x * (img->bpp / 8);
    *(unsigned int *)(img->pxl + position) = colour;
}