/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 08:48:13 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/21 11:44:46 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static void	init_side_ray(t_data *data, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player.pos_y)
			* ray->delta_dist_y;
	}
}

static void	send_ray(t_data *data, t_ray *ray)
{
	int	status;

	status = 0;
	while (status == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x < 0 || ray->map_x >= data->map_width || ray->map_y < 0
			|| ray->map_y >= data->map_height)
		{
			status = 1;
			break ;
		}
		if (data->map[ray->map_y][ray->map_x] == '1')	
			status = 1;
	}
}

static void	cast_single_ray(t_data *data, int col)
{
	t_ray	ret;
	double	camera_x;

	ret.map_x = (int)data->player.pos_x;
	ret.map_y = (int)data->player.pos_y;
	camera_x = 2 * col / (double)SCREEN_WIDTH - 1;
	ret.ray_dir_x = data->player.dir_x + data->player.plane_x * camera_x;
	ret.ray_dir_y = data->player.dir_y + data->player.plane_y * camera_x;
	if (ret.ray_dir_x != 0)
		ret.delta_dist_x = fabs(1 / ret.ray_dir_x);
	else
		ret.delta_dist_x = fabs(1 / (1e-30));
	if (ret.ray_dir_y != 0)
		ret.delta_dist_y = fabs(1 / ret.ray_dir_y);
	else
		ret.delta_dist_y = fabs(1 / (1e-30));
	init_side_ray(data, &ret);
	send_ray(data, &ret);
	if (ret.side == 0)
		ret.perp_dist = (ret.map_x - data->player.pos_x + (1 - ret.step_x) / 2)
			/ ret.ray_dir_x;
	else
		ret.perp_dist = (ret.map_y - data->player.pos_y + (1 - ret.step_y) / 2)
			/ ret.ray_dir_y;
	ret.line_height = (int)(SCREEN_HEIGHT / ret.perp_dist);
	draw_text(data, &ret, col);
}

void	raycasting(t_data *data)
{
	int col;

	col = 0;
	data->player.dir_x = cos(data->player.orientation);
	data->player.dir_y = sin(data->player.orientation);
	data->player.plane_y = data->player.dir_x * PLANE_SIZE;
	data->player.plane_x = -data->player.dir_y *  PLANE_SIZE;
	while (col < SCREEN_WIDTH)
	{
		cast_single_ray(data, col);
		col++;
	}
	draw_minimap_rotate(data);
	if (data->show_trapeze)
	{
		draw_trapeze_map(data);
		// draw_trapeze_from_image(data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img_ptr, 0, 0);
	// mlx_put_image_to_window(data->mlx, data->win, data->player_in_minimap.img_ptr
	// 	, MINIMAP_SIZE / 2 - MINIMAP_TILS / 4
	// 	, MINIMAP_SIZE / 2 - MINIMAP_TILS / 2);
	mlx_put_image_to_window(data->mlx, data->win, data->texture.triangle_icon.img_ptr
		, MINIMAP_SIZE / 2 - MINIMAP_TILS / 4
		, MINIMAP_SIZE / 2 - MINIMAP_TILS / 2);
	// mlx_put_image_to_window(data->mlx, data->win, data->map_img->img_ptr, 100, 100);
}
