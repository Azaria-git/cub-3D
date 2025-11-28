/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 08:48:13 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/28 17:44:23 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

#include <stdlib.h> // pour abs



void dbg_trace_line(t_ray *ray, t_coord src, t_coord dest, t_img *img)
{
    int tile_big = TILE_SIZE;
    int tile_dbg = MINIMAP_TILS;
	int color;

    // 1. Scale sources to debug map
    src.x = (src.x * tile_dbg) / tile_big;
    src.y = (src.y * tile_dbg) / tile_big;
    dest.x = (dest.x * tile_dbg) / tile_big;
    dest.y = (dest.y * tile_dbg) / tile_big;

    // 2. Bresenham
    int dx = abs(dest.x - src.x);
    int dy = -abs(dest.y - src.y);
    int sx = src.x < dest.x ? 1 : -1;
    int sy = src.y < dest.y ? 1 : -1;
    int err = dx + dy;

    int x = src.x;
    int y = src.y;

    while (1)
    {
		if (ray->side_v)
		{
			color = 0xff0000;
		}
		else
			color = 0xffffff;
        my_mlx_pixel_put(img, x, y, color);

        if (x == dest.x && y == dest.y)
            break;

        int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x += sx; }
        if (e2 <= dx) { err += dx; y += sy; }
    }
}

void step_calculation(t_data *data, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step.x = -TILE_SIZE;
	    ray->v.x = ray->map_pxl.x;
	}
	else
	{
		ray->step.x = TILE_SIZE;
	    ray->v.x = ray->map_pxl.x + TILE_SIZE;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step.y = -TILE_SIZE;
	    ray->h.y = ray->map_pxl.y;
	}
	else
	{
		ray->step.y = TILE_SIZE;
	    ray->h.y = ray->map_pxl.y + TILE_SIZE;
	}
	// horizontal
	ray->h.x = data->player.pxl_pos.x
			+ (ray->h.y - data->player.pxl_pos.y) * (ray->ray_dir_x / ray->ray_dir_y);

	// limiter à la map
	if (ray->h.x < 0)
		ray->h.x = 0;
	if (ray->h.x > data->map_width * TILE_SIZE - 1)
		ray->h.x = data->map_width * TILE_SIZE - 1;

	// vertical
	ray->v.y = data->player.pxl_pos.y
			+ (ray->v.x - data->player.pxl_pos.x) * (ray->ray_dir_y / ray->ray_dir_x);

	if (ray->v.y < 0)
		ray->v.y = 0;
	if (ray->v.y > data->map_height * TILE_SIZE - 1)
		ray->v.y = data->map_height * TILE_SIZE - 1;
}

void	ray_v(t_data *data, t_ray *ray)
{
	int map_x;
	int map_y;

	double delta_y = ray->step.x * (ray->ray_dir_y / ray->ray_dir_x);
	// double delta_y = ray->step.x * tan(ray->angle);

	while (1)
	{
		if (ray->v.x < 0 || (ray->v.x > data->map_width * TILE_SIZE - 1)
			|| ray->v.y < 0 || (ray->v.y > data->map_height * TILE_SIZE - 1))
		{
			ray->v.y = -1;
			ray->v.x = -1;
			break;
		}
		if (ray->ray_dir_x < 0)
			map_x = ((ray->v.x - 1) / TILE_SIZE);
		else
			map_x = ray->v.x / TILE_SIZE;

		if (ray->ray_dir_y < 0)
			map_y = ((ray->v.y - 1) / TILE_SIZE);
		else
			map_y = ray->v.y / TILE_SIZE;

		if (data->map[map_y][map_x] == '1')
			break;
		ray->v.x += ray->step.x;
		ray->v.y += delta_y;
	}
}

void	ray_h(t_data *data, t_ray *ray)
{
	int map_x;
	int map_y;

	double delta_x = ray->step.y * (ray->ray_dir_x / ray->ray_dir_y);
	// double delta_x = ray->step.y / tan(ray->angle);
	
	while (1)
	{
		if (ray->h.x < 0 || (ray->h.x > data->map_width * TILE_SIZE - 1)
			|| ray->h.y < 0 || (ray->h.y > data->map_height * TILE_SIZE - 1))
		{
			ray->h.y = -1;
			ray->h.x = -1;
			break;
		}
		if (ray->ray_dir_x < 0)
			map_x = ((ray->h.x - 1) / TILE_SIZE);
		else
			map_x = ray->h.x / TILE_SIZE;

		if (ray->ray_dir_y < 0)
			map_y = ((ray->h.y - 1) / TILE_SIZE);
		else
			map_y = ray->h.y / TILE_SIZE;
		if (data->map[map_y][map_x] == '1')
			break;
		ray->h.x += delta_x;
		ray->h.y += ray->step.y;
	}
}

void send_a_ray(t_data *data, int col)
{
    t_ray ray;
    float camera_x;

    camera_x = 2 * col / (float)SCREEN_WIDTH - 1;
	ray.map_pxl.x = (int)(data->player.pxl_pos.x / TILE_SIZE) * TILE_SIZE;
	ray.map_pxl.y = (int)(data->player.pxl_pos.y / TILE_SIZE) * TILE_SIZE;
    ray.ray_dir_x = data->player.dir_x + data->player.plane_x * camera_x;
    ray.ray_dir_y = data->player.dir_y + data->player.plane_y * camera_x;
	ray.angle = atan2(ray.ray_dir_y, ray.ray_dir_x);
	ray.is_door = 0;
	

	step_calculation(data, &ray);
	ray_h(data, &ray);
	ray_v(data, &ray);
	float dist_v = INFINITY;
	float dist_h = INFINITY;
	
	if (ray.v.x >= 0)
		dist_v = sqrt(pow(ray.v.x - data->player.pxl_pos.x, 2.0) + pow(ray.v.y - data->player.pxl_pos.y, 2.0));
	if (ray.h.x >= 0)
		dist_h = sqrt(pow(ray.h.x - data->player.pxl_pos.x, 2.0) + pow(ray.h.y - data->player.pxl_pos.y, 2.0));
	if (ray.v.x >= 0 && dist_v < dist_h)
	{
		ray.side_v = 1;
		ray.perp_dist = dist_v;
		ray.pxl_dest.x = ray.v.x;
		ray.pxl_dest.y = ray.v.y;
		
	}
	else
	{
		ray.side_v = 0;
		ray.perp_dist = dist_h;
		ray.pxl_dest.x = ray.h.x;
		ray.pxl_dest.y = ray.h.y;

	}
	dbg_trace_line(&ray, data->player.pxl_pos, ray.pxl_dest, &data->dbg.img);	
	if (col < SCREEN_WIDTH / 2)
		ray.perp_dist = ray.perp_dist * cos(ray.angle - data->player.orientation);
	else
		ray.perp_dist = ray.perp_dist * cos(data->player.orientation - ray.angle);
	ray.line_height = TILE_SIZE / (ray.perp_dist) * ((SCREEN_WIDTH / 2) / tan(data->fov / 2));
	texturing(data, &ray, col);
}


void	raycasting(t_data *data)
{
	int	col;

	col = 0;
	data->player.dir_x = cos(data->player.orientation);
	data->player.dir_y = sin(data->player.orientation);
	data->player.plane_y = data->player.dir_x * PLANE_SIZE;
	data->player.plane_x = -data->player.dir_y * PLANE_SIZE;

	//dbg
		map_img_dbg(data, &data->dbg.img);
	//dbg
	while (col < SCREEN_WIDTH)
	{
		// if (col != SCREEN_WIDTH / 2)
		// if (col == (SCREEN_WIDTH / 2))
			send_a_ray(data, col);
		col++;
		// col += TILE_SIZE;
	}
	draw_minimap_rotate(data);
	if (data->show_trapeze)
		draw_trapeze_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img_ptr, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win,
		data->texture.triangle_icon.img_ptr, MINIMAP_SIZE / 2 - MINIMAP_TILS
		/ 4, MINIMAP_SIZE / 2 - MINIMAP_TILS / 2);
	//dbg
	mlx_put_image_to_window(data->mlx, data->dbg.win, data->dbg.img.img_ptr, 0, 0);
	//dbg
}
