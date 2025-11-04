/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:16:35 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/04 12:18:04 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "graph.h"

double text_x_calculation(t_data *data, t_ray *ray)
{
	double	wall_x;
	int		text_x;

	if (!ray->side)
	{
		wall_x = data->player.pos_y + ray->perp_dist * ray->ray_dir_y;
		if (ray->ray_dir_x > 0)
			data->texture.current = &data->texture.img_ea;
		else
			data->texture.current = &data->texture.img_we;
	}
	else
	{
    	wall_x = data->player.pos_x + ray->perp_dist * ray->ray_dir_x;
		if (ray->ray_dir_y > 0)
			data->texture.current = &data->texture.img_so;
		else
			data->texture.current = &data->texture.img_no;
	}
	wall_x -= floor(wall_x);
	text_x = (int) (wall_x * (double) TILE_SIZE);
	if (ray->side == 0 && ray->ray_dir_x > 0)
    	text_x = TILE_SIZE - text_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
    	text_x = TILE_SIZE - text_x - 1;
	return (text_x);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
