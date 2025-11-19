/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:30:57 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/19 17:07:40 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./pars/parsing.h"
# include "./graph/graph.h"
# include "./common/common.h"
# include "./event/event.h"
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>

static void creat_img_triangle(t_data *data, t_img *img, int width, int height)
{
	t_coord centre;
    int x;
    int y;
    
    img->img_ptr = mlx_new_image(data->mlx, width, height);
    img->addr = mlx_get_data_addr(img->img_ptr,
                                 &img->bits_per_pixel,
                                 &img->line_length,
                                 &img->endian);
    centre.x = width / 2;
    centre.y = height / 2;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            if (y > centre.x - x && y > x - centre.x)
                my_mlx_pixel_put(img, x, y, 0xFF0000);
            x++;
        }
        y++;
    }
}

static void map_img(t_data *data, t_img *map_img)
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

// static void map_img(t_data *data, t_img *map_img)
// {
// 	t_coord map;
// 	int color;

// 	map_img->img_ptr = mlx_new_image(data->mlx, data->map_width * MINIMAP_TILS
// 		, data->map_height * MINIMAP_TILS);
// 	map_img->addr = mlx_get_data_addr(map_img->img_ptr
// 		, &map_img->bits_per_pixel
// 		, &map_img->line_length
// 		, &map_img->endian);
// 	map.y = 0;
// 	color = 0x0000ff;
// 	while (map.y < (data->map_height * MINIMAP_TILS))
// 	{
// 		map.x = 0;
// 		while (map.x < (data->map_width * MINIMAP_TILS))
// 		{
// 			if (data->map[map.y / MINIMAP_TILS][map.x / MINIMAP_TILS] == '1')
// 				my_mlx_pixel_put(map_img, map.x, map.y, 0x444444);
// 			else if (data->map[map.y / MINIMAP_TILS][map.x / MINIMAP_TILS] == 'X')
// 			{
// 				int cell_x = map.x % MINIMAP_TILS;
// 				int cell_y = map.y % MINIMAP_TILS;

// 				int tex_x = cell_x * data->texture.space_tex.width / MINIMAP_TILS;
// 				int tex_y = cell_y * data->texture.space_tex.height / MINIMAP_TILS;
// 				// printf("tex x=%d and tex y = %d", tex_x, tex_y);
// 				// color = get_pixel_color(&data->texture.space_tex, tex_x, tex_y);

// 				my_mlx_pixel_put(map_img, map.x, map.y, color);
// 			}
// 			else
// 				my_mlx_pixel_put(map_img, map.x ,map.y, 0x888888);
// 			map.x++;
// 		}	
// 		map.y++;
// 	}
// }

static void texture_init(t_data *data)
{
	data->texture.img_ea.img_ptr = mlx_xpm_file_to_image(data->mlx
		, data->texture.east
		, &data->texture.width
		, &data->texture.height);
	data->texture.img_we.img_ptr = mlx_xpm_file_to_image(data->mlx
		, data->texture.west
		, &data->texture.width
		, &data->texture.height);
	data->texture.img_no.img_ptr = mlx_xpm_file_to_image(data->mlx
		, data->texture.north
		, &data->texture.width
		, &data->texture.height);
	data->texture.img_so.img_ptr = mlx_xpm_file_to_image(data->mlx
		, data->texture.south
		, &data->texture.width
		, &data->texture.height);
	data->texture.space_tex.img_ptr = mlx_xpm_file_to_image(data->mlx
		, "./images/sea.xpm"
		, &data->texture.space_tex.width
		, &data->texture.space_tex.width);
	data->texture.wall_tex.img_ptr = mlx_xpm_file_to_image(data->mlx
		, "./images/map_wall.xpm"
		, &data->texture.wall_tex.width
		, &data->texture.wall_tex.width);
	data->texture.floor_tex.img_ptr = mlx_xpm_file_to_image(data->mlx
		, "./images/floor.xpm"
		, &data->texture.floor_tex.width
		, &data->texture.floor_tex.width);
		//
	data->texture.img_ea.addr = mlx_get_data_addr(data->texture.img_ea.img_ptr
	, &data->texture.img_ea.bits_per_pixel
	, &data->texture.img_ea.line_length
	, &data->texture.img_ea.endian);
	data->texture.img_we.addr = mlx_get_data_addr(data->texture.img_we.img_ptr
	, &data->texture.img_we.bits_per_pixel
	, &data->texture.img_we.line_length
	, &data->texture.img_we.endian);
	data->texture.img_so.addr = mlx_get_data_addr(data->texture.img_so.img_ptr
	, &data->texture.img_so.bits_per_pixel
	, &data->texture.img_so.line_length
	, &data->texture.img_so.endian);
	data->texture.img_no.addr = mlx_get_data_addr(data->texture.img_no.img_ptr
	, &data->texture.img_no.bits_per_pixel
	, &data->texture.img_no.line_length
	, &data->texture.img_no.endian);
	data->texture.space_tex.addr = mlx_get_data_addr(data->texture.space_tex.img_ptr
	, &data->texture.space_tex.bits_per_pixel
	, &data->texture.space_tex.line_length
	, &data->texture.space_tex.endian);
	data->texture.wall_tex.addr = mlx_get_data_addr(data->texture.wall_tex.img_ptr
	, &data->texture.wall_tex.bits_per_pixel
	, &data->texture.wall_tex.line_length
	, &data->texture.wall_tex.endian);
	data->texture.floor_tex.addr = mlx_get_data_addr(data->texture.floor_tex.img_ptr
	, &data->texture.floor_tex.bits_per_pixel
	, &data->texture.floor_tex.line_length
	, &data->texture.floor_tex.endian);
	creat_img_triangle(data, &data->player_in_minimap, MINIMAP_TILS / 2, MINIMAP_TILS);
}

static void screen_init(t_data *data, t_img *img, t_img *mp_img)
{
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH
		, SCREEN_HEIGHT, "Cub 3D");
	img->img_ptr = mlx_new_image(data->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	data->img = img;
	map_img(data, mp_img);
	data->map_img = mp_img;
}

static int data_init(t_data *data, t_img *img, t_img *map_img)
{
	data->mlx = mlx_init();
    if (!data->mlx)
    {
		print_error("mlx", "mlx_init() failed");
		ft_free_data(&data);
        return (1);
    }
	texture_init(data);
	screen_init(data, img, map_img);
	data->trap_start.x = (SCREEN_WIDTH / 2) - (data->map_screen_width / 2);
	// data->trap_start.y = ((SCREEN_HEIGHT / 2) - (data->map_screen_height / 2));
	data->trap_start.y = SCREEN_HEIGHT - data->map_screen_height;
	return (0);
}

int	main(int c, char **v)
{
	t_data *data;
	t_img img;
	t_img map_img;

	if (c != 2)
		return (1);
	data = check_and_filling(v[1]);
	if (!data)
		return (1);
	if (data_init(data, &img, &map_img))
		return (1);
	raycasting(data);
	listening_act(data);
	mlx_key_hook(data->win, key_hook, (void *) data);
	mlx_loop(data->mlx);
	return (0);
}
