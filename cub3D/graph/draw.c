/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:53:53 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/18 16:49:40 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./graph.h"

void draw_minimap_rotate(t_data *data)
{
    float c_x, c_y, r_x, r_y;
    t_coord pxl;
    int src_x, src_y;
    int color;
    int radius = MINIMAP_SIZE / 2;
	float decal = 1.570796;
	
    pxl.y = 0;
    while (pxl.y < MINIMAP_SIZE)
    {
        pxl.x = 0;
        while (pxl.x < MINIMAP_SIZE)
        {
            c_x = pxl.x - radius;
            c_y = pxl.y - radius;
            if (c_x * c_x + c_y * c_y > radius * radius)
            {
                pxl.x++;
                continue;
            }
            r_x = c_x * cos(data->player.orientation + decal) - c_y * sin(data->player.orientation + decal);
            r_y = c_x * sin(data->player.orientation + decal) + c_y * cos(data->player.orientation + decal);
            src_x = (int)(data->player.pos_x * MINIMAP_TILS + r_x);
            src_y = (int)(data->player.pos_y * MINIMAP_TILS + r_y);
            if (src_x >= 0 && src_x < data->map_width * MINIMAP_TILS &&
                src_y >= 0 && src_y < data->map_height * MINIMAP_TILS)
            {
                color = get_pixel_color(data->map_img, src_x, src_y);
            }
            else
                color = 0x888888;
            my_mlx_pixel_put(data->img, pxl.x, pxl.y, color);
            pxl.x++;
        }
        pxl.y++;
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

static void	draw_wall(t_data *data, t_ray *ray, int colon, t_tex *text)
{
	int		x;
	int		text_y;
	double	text_pos;
	int		color;

	x = ray->draw_start;
	text_pos = (ray->draw_start - data->mid_height + ray->line_height / 2);
	if (text_pos < 0)
		text_pos = 0;
	text_pos *=  text->step;
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
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
	text.text_x = text_x_calculation(data, ray);
	text.step = (double)TILE_SIZE / ray->line_height;
	draw_ceiling_and_floor(data, ray, colon);
	draw_wall(data, ray, colon, &text);
}

void draw_player(t_data *data, int img_x, int img_y)
{
	double x;
	double y;
	double step;
	int i;

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
