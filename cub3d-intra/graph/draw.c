/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:53:53 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/28 07:15:31 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./graph.h"

void map_img_dbg(t_data *data, t_img *map_img)
{
	t_coord map;
	int color;
	int x;
	int y;
	map.y = 0;
	color = 0x0000ff;

	while (map.y < data->map_height)
	{
		map.x = 0;
		while (map.x < data->map_width)
		{
			if (data->map[map.y][map.x] == '1')
			{
				y = -1;
				while (++y <= MINIMAP_TILS)
				{
					x = -1;
					while (++x <= MINIMAP_TILS)
					{
						color = get_pixel_color(&data->texture.wall_tex, x, y);
						my_mlx_pixel_put(map_img, map.x * MINIMAP_TILS + x, map.y * MINIMAP_TILS + y, color);
					}
				}
			}
			else if (data->map[map.y][map.x] == 'X')
			{
				y = -1;
				while (++y <= MINIMAP_TILS)
				{
					x = -1;
					while (++x <= MINIMAP_TILS)
					{
						color = get_pixel_color(&data->texture.floor_tex, x, y);
						my_mlx_pixel_put(map_img, map.x * MINIMAP_TILS + x, map.y * MINIMAP_TILS + y, color);
					}
				}
			}
			else if (data->map[map.y][map.x] == 'D')
			{
				y = -1;
				while (++y <= MINIMAP_TILS)
				{
					x = -1;
					while (++x <= MINIMAP_TILS)
					{
						color = get_pixel_color(&data->texture.floor_tex, x, y);
						my_mlx_pixel_put(map_img, map.x * MINIMAP_TILS + x, map.y * MINIMAP_TILS + y, color);
					}
				}
			}
			else
			{
				y = -1;
				while (++y <= MINIMAP_TILS)
				{
					x = -1;
					while (++x <= MINIMAP_TILS)
					{
						color = get_pixel_color(&data->texture.space_tex, x, y);
						my_mlx_pixel_put(map_img, map.x * MINIMAP_TILS + x  ,map.y * MINIMAP_TILS + y, color);
					}
				}
			}
			map.x++;
		}	
		map.y++;
	}
}

void map_img(t_data *data, t_img *map_img)
{
	t_coord map;
	int color;
	int x;
	int y;
	map_img->img_ptr = mlx_new_image(data->mlx, data->map_width * MINIMAP_TILS
		, data->map_height * MINIMAP_TILS);
	map_img->addr = mlx_get_data_addr(map_img->img_ptr
		, &map_img->bits_per_pixel
		, &map_img->line_length
		, &map_img->endian);
	map.y = 0;
	color = 0x0000ff;
	while (map.y < data->map_height)
	{
		map.x = 0;
		while (map.x < data->map_width)
		{
			if (data->map[map.y][map.x] == '1')
			{
				y = -1;
				while (++y <= MINIMAP_TILS)
				{
					x = -1;
					while (++x <= MINIMAP_TILS)
					{
						color = get_pixel_color(&data->texture.wall_tex, x, y);
						my_mlx_pixel_put(map_img, map.x * MINIMAP_TILS + x, map.y * MINIMAP_TILS + y, color);
					}
				}
			}
			else if (data->map[map.y][map.x] == 'X')
			{
				y = -1;
				while (++y <= MINIMAP_TILS)
				{
					x = -1;
					while (++x <= MINIMAP_TILS)
					{
						color = get_pixel_color(&data->texture.floor_tex, x, y);
						my_mlx_pixel_put(map_img, map.x * MINIMAP_TILS + x, map.y * MINIMAP_TILS + y, color);
					}
				}
			}
			else if (data->map[map.y][map.x] == 'D')
			{
				y = -1;
				while (++y <= MINIMAP_TILS)
				{
					x = -1;
					while (++x <= MINIMAP_TILS)
					{
						color = get_pixel_color(&data->texture.floor_tex, x, y);
						my_mlx_pixel_put(map_img, map.x * MINIMAP_TILS + x, map.y * MINIMAP_TILS + y, color);
					}
				}
			}
			else
			{
				y = -1;
				while (++y <= MINIMAP_TILS)
				{
					x = -1;
					while (++x <= MINIMAP_TILS)
					{
						color = get_pixel_color(&data->texture.space_tex, x, y);
						my_mlx_pixel_put(map_img, map.x * MINIMAP_TILS + x  ,map.y * MINIMAP_TILS + y, color);
					}
				}
			}
			map.x++;
		}	
		map.y++;
	}
}

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
	while (x < SCREEN_HEIGHT)
	{
		if (x < 0 || x >= SCREEN_HEIGHT)
			return ;
		my_mlx_pixel_put(data->img, colon, x, data->color_floor);
		x++;
	}
}

void texturing(t_data *data, t_ray *ray, int colon)
{
	int pxl_text_x;
	
	if (ray->side_v)
	{
		pxl_text_x = ray->pxl_dest.y % TILE_SIZE;
		if (ray->ray_dir_x > 0)
		{
			if (ray->is_door)
				data->texture.current = &data->texture.door_ea;
			else			
				data->texture.current = &data->texture.img_ea;	
		}		
		else
		{
			if (ray->is_door)
				data->texture.current = &data->texture.door_we;
			else
				data->texture.current = &data->texture.img_we;
		}
	}
	else
	{
		pxl_text_x = ray->pxl_dest.x % TILE_SIZE;
		if (ray->ray_dir_y > 0)
		{
			if (ray->is_door)
				data->texture.current = &data->texture.door_so;
			else
				data->texture.current = &data->texture.img_so;
		}
		else
		{
			if (ray->is_door)
				data->texture.current = &data->texture.door_no;
			else
				data->texture.current = &data->texture.img_no;
		}
	}
	if (ray->side_v == 0 && ray->ray_dir_x > 0)
		pxl_text_x = TILE_SIZE - pxl_text_x - 1;
	if (ray->side_v == 1 && ray->ray_dir_y < 0)
		pxl_text_x = TILE_SIZE - pxl_text_x - 1;


	ray->draw_start = -ray->line_height / 2 + data->mid_height;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->mid_height;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
	double step = (double)TILE_SIZE / ray->line_height;

	int		x;
	int		text_y;
	double	text_pos;
	int		color;

	x = ray->draw_start;
	text_pos = (ray->draw_start - data->mid_height + ray->line_height / 2);
	if (text_pos < 0)
		text_pos = 0;
	text_pos *= step;
	while (x < ray->draw_end)
	{
		text_y = (int)text_pos % TILE_SIZE;
		text_pos += step;
		color = ((int *)data->texture.current->addr)[TILE_SIZE * text_y
			+ pxl_text_x];
		my_mlx_pixel_put(data->img, colon, x, color);
		x++;
	}
	draw_ceiling_and_floor(data, ray, colon);
}

void	draw_player(t_data *data, int img_x, int img_y)
{
	double	x;
	double	y;
	double	step;
	int		i;

	x = img_x;
	y = img_y;
	step = 0.05;
	i = 0;
	while (i < 100)
	{
		my_mlx_pixel_put(data->img, x, y, 0x00FF00);
		x += cos(data->player.orientation) * step;
		y += sin(data->player.orientation) * step;
		i++;
	}
}
