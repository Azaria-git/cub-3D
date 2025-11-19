/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trapeze_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:19:26 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/19 17:20:19 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	draw_trapeze_map(t_data *data)
{
	t_coord	map;
	int		x_trap;
	int		top_width;
	int		x_offset;
	int		line_width;

	top_width = data->map_width * MINIMAP_TILS * 0.7;
	map.y = 0;
	while (map.y < data->map_screen_height)
	{
		line_width = top_width + ((data->map_screen_width - top_width) * map.y)
			/ data->map_screen_height;
		x_offset = (data->map_screen_width - line_width) / 2;
		map.x = 0;
		while (map.x < data->map_width * MINIMAP_TILS)
		{
			x_trap = map.x * line_width / (data->map_width * MINIMAP_TILS)
				+ x_offset;
			if (data->map[map.y / MINIMAP_TILS][map.x / MINIMAP_TILS] == '1')
				my_mlx_pixel_put(data->img, x_trap + data->trap_start.x, map.y
					+ data->trap_start.y, 0x444444);
			else if (data->player.map_y == map.y / MINIMAP_TILS
				&& data->player.map_x == map.x / MINIMAP_TILS)
				my_mlx_pixel_put(data->img, x_trap + data->trap_start.x, map.y
					+ data->trap_start.y, 0xFF0000);
			else if (data->map[map.y / MINIMAP_TILS][map.x
				/ MINIMAP_TILS] != 'X')
				my_mlx_pixel_put(data->img, x_trap + data->trap_start.x, map.y
					+ data->trap_start.y, 0x888888);
			map.x++;
		}
		map.y++;
	}
}

// void draw_minimap_rotate(t_data *data)
// {
//     float c_x, c_y, r_x, r_y;
//     t_coord pxl;
//     int src_x, src_y;
//     int color;
//     int radius = MINIMAP_SIZE / 2;
// 	float decal = 1.570796;
	
//     pxl.y = 0;
//     while (pxl.y < MINIMAP_SIZE)
//     {
//         pxl.x = 0;
//         while (pxl.x < MINIMAP_SIZE)
//         {
//             c_x = pxl.x - radius;
//             c_y = pxl.y - radius;
//             if (c_x * c_x + c_y * c_y > radius * radius)
//             {
//                 pxl.x++;
//                 continue;
//             }
//             r_x = c_x * cos(data->player.orientation + decal) - c_y * sin(data->player.orientation + decal);
//             r_y = c_x * sin(data->player.orientation + decal) + c_y * cos(data->player.orientation + decal);
//             src_x = (int)(data->player.pos_x * MINIMAP_TILS + r_x);
//             src_y = (int)(data->player.pos_y * MINIMAP_TILS + r_y);
//             if (src_x >= 0 && src_x < data->map_width * MINIMAP_TILS &&
//                 src_y >= 0 && src_y < data->map_height * MINIMAP_TILS)
//             {
//                 color = get_pixel_color(data->map_img, src_x, src_y);
//             }
//             else
//                 color = 0x0000ff;
//             my_mlx_pixel_put(data->img, pxl.x, pxl.y, color);
//             pxl.x++;
//         }
//         pxl.y++;
//     }
// }