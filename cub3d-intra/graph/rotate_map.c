/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:19:26 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/26 14:42:21 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static void	draw_sprite(t_data *data)
{
	t_coord	size;
	t_coord	trap;
	int		line_w;

	trap.y = ((data->player.pxl_pos.y / TILE_SIZE) * MINIMAP_TILS);
	line_w = data->trap_top_width + ((data->map_screen_width
				- data->trap_top_width) * trap.y) / data->map_screen_height;
	trap.x = (((data->player.pxl_pos.x / TILE_SIZE) * MINIMAP_TILS) / (float)(data->map_width
				* MINIMAP_TILS)) * line_w + ((data->map_screen_width - line_w)
			/ 2);
	size.y = -1;
	while (++size.y < data->texture.location_icon.height)
	{
		size.x = -1;
		while (++size.x < data->texture.location_icon.width)
		{
			my_mlx_pixel_put(data->img, data->trap_start.x + trap.x
				- (data->texture.location_icon.width / 2) + size.x,
				data->trap_start.y + trap.y
				- (data->texture.location_icon.height / 2) + size.y,
				get_pixel_color(&data->texture.location_icon, size.x, size.y));
		}
	}
}

static void	put_trap(t_data *data, t_coord *src, t_coord *pxl)
{
	my_mlx_pixel_put(data->img, data->trap_start.x + data->trap_x_offset
		+ pxl->x, data->trap_start.y + pxl->y, get_pixel_color(data->map_img,
			src->x, src->y));
}

static void	put_rotat(t_data *data, t_coord *src, t_coord *pxl)
{
	if (src->x >= 0 && src->x < data->map_width * MINIMAP_TILS && src->y >= 0
		&& src->y < data->map_height * MINIMAP_TILS)
		my_mlx_pixel_put(data->img, pxl->x, pxl->y,
			get_pixel_color(data->map_img, src->x, src->y));
	else
		my_mlx_pixel_put(data->img, pxl->x, pxl->y, 0x0000ff);
}

void	draw_trapeze_map(t_data *data)
{
	t_coord	pxl;
	t_coord	src;
	int		line_width;

	data->trap_top_width = data->map_screen_width * 0.7;
	pxl.y = -1;
	while (++pxl.y < data->map_screen_height)
	{
		line_width = data->trap_top_width + ((data->map_screen_width
					- data->trap_top_width) * pxl.y) / data->map_screen_height;
		data->trap_x_offset = (data->map_screen_width - line_width) / 2;
		pxl.x = -1;
		while (++pxl.x < line_width)
		{
			src.x = ((float)pxl.x / (float)line_width) * (data->map_width
					* MINIMAP_TILS);
			src.y = ((float)pxl.y / (float)data->map_screen_height)
				* (data->map_height * MINIMAP_TILS);
			if (src.x >= 0 && src.x < data->map_screen_width && src.y >= 0
				&& src.y < data->map_screen_height)
				put_trap(data, &src, &pxl);
		}
	}
	draw_sprite(data);
}

void	draw_minimap_rotate(t_data *data)
{
	t_coord	pxl;
	t_coord	circle;
	t_coord	src;
	float	r_x;
	float	r_y;

	pxl.y = -1;
	while (++pxl.y < MINIMAP_SIZE)
	{
		pxl.x = -1;
		while (++pxl.x < MINIMAP_SIZE)
		{
			circle.x = pxl.x - RADIUS;
			circle.y = pxl.y - RADIUS;
			if (circle.x * circle.x + circle.y * circle.y > (RADIUS * RADIUS))
				continue ;
			r_x = circle.x * cos(data->player.orientation + 1.570796) - circle.y
				* sin(data->player.orientation + 1.570796);
			r_y = circle.x * sin(data->player.orientation + 1.570796) + circle.y
				* cos(data->player.orientation + 1.570796);
			src.x = (int)((data->player.pxl_pos.x / 64) * MINIMAP_TILS + r_x);
			src.y = (int)(((data->player.pxl_pos.y / 64)) * MINIMAP_TILS + r_y);
			put_rotat(data, &src, &pxl);
		}
	}
}
