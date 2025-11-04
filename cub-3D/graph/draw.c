/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:53:53 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/04 12:23:22 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./graph.h"

 static void	draw_ceiling_and_floor(t_data *data, t_ray *ray, int colon)
{
	int	x;

	x = 0;
	while (x < ray->draw_start)
	{
		my_mlx_pixel_put(data->img, colon, x, data->color_ceiling);
		x++;
	}
	x = ray->draw_end;
	while (x < data->screen_height)
	{
		if (x < 0 || x >= data->screen_height)
			return ;
		my_mlx_pixel_put(data->img, colon, x, data->color_floor);
		x++;
	}
}

static void	draw_wall(t_data *data, t_ray *ray, int colon, t_tex *text)
{
	int		x;
	int		text_y;
	double	text_pos;
	int		color;

	x = ray->draw_start;
	text_pos = (ray->draw_start - data->mid_height + ray->line_height / 2)
		* text->step;
	while (x < ray->draw_end)
	{
		text_y = (int)text_pos % TILE_SIZE;
		text_pos += text->step;
		color = ((int *)data->texture.current->addr)[TILE_SIZE * text_y
			+ text->text_x];
		my_mlx_pixel_put(data->img, colon, x, color);
		x++;
	}
}

void draw_text(t_data *data, t_ray *ray, int colon)
{
	t_tex	text;

	ray->draw_start = -ray->line_height / 2 + data->mid_height;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->mid_height;
	if (ray->draw_end >= data->screen_height)
		ray->draw_end = data->screen_height - 1;
	text.text_x = text_x_calculation(data, ray);
	text.step = (double)TILE_SIZE / ray->line_height;
	draw_ceiling_and_floor(data, ray, colon);
	draw_wall(data, ray, colon, &text);
}

void	draw_rays(t_data *data, int col)
{
	t_ray	ray;
	double	step;
	t_coord	pos;

	ray.ray_angle = data->player.orientation - data->mi_fov + ((double)col
			/ (double)data->mini_map->screen_width) * data->fov;
	ray.ray_dir_x = data->player.pos_x;
	ray.ray_dir_y = data->player.pos_y;
	step = 1;
	while (1)
	{
		pos.x = (int)(ray.ray_dir_x * MINIMAP_TILS);
		pos.y = (int)(ray.ray_dir_y * MINIMAP_TILS);
		my_mlx_pixel_put(data->img, pos.x, pos.y, 0x00FF00);
		ray.ray_dir_x += cos(ray.ray_angle) * step;
		ray.ray_dir_y += sin(ray.ray_angle) * step;
		ray.map_x = (int)ray.ray_dir_x;
		ray.map_y = (int)ray.ray_dir_y;
		if (ray.map_y < 0 || ray.map_y >= data->map_height || ray.map_x < 0
			|| ray.map_x >= data->map_width)
			break ;
		if (data->map[ray.map_y][ray.map_x] == '1')
			break ;
	}
}

void	draw_terrain(t_data *data)
{
	t_coord w_c;
	t_coord map_c;
	int color;

	map_c.x = 0;
	map_c.y = 0;
	w_c.y = -1;
	color = 0x222222;
	while (++w_c.y < data->mini_map->screen_height)
	{
		w_c.x = -1;
		while (++w_c.x < data->mini_map->screen_width)
		{
			map_c.x = w_c.x / MINIMAP_TILS;
			map_c.y = w_c.y / MINIMAP_TILS;
			if (data->map[map_c.y][map_c.x] == '1')
				my_mlx_pixel_put(data->img, w_c.x, w_c.y, color);
		}
	}
}