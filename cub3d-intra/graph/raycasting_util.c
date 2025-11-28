/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:16:35 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/26 13:34:32 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_img *img, int pxl_x, int pxl_y)
{
	char	*pixel;
	int		color;

	pixel = img->addr + (pxl_y * img->line_length + pxl_x * (img->bits_per_pixel
				/ 8));
	color = *(int *)pixel;
	return (color);
}
