/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:30:57 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/28 07:13:31 by aravelom         ###   ########.fr       */
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



static void texture_init(t_data *data)
{
	data->texture.img_ea.img_ptr = mlx_xpm_file_to_image(data->mlx
		, data->texture.east
		, &data->texture.img_ea.width
		, &data->texture.img_ea.height);
	data->texture.img_we.img_ptr = mlx_xpm_file_to_image(data->mlx
		, data->texture.west
		, &data->texture.img_we.width
		, &data->texture.img_we.height);
	data->texture.img_no.img_ptr = mlx_xpm_file_to_image(data->mlx
		, data->texture.north
		, &data->texture.img_no.width
		, &data->texture.img_no.height);
	data->texture.img_so.img_ptr = mlx_xpm_file_to_image(data->mlx
		, data->texture.south
		, &data->texture.img_so.width
		, &data->texture.img_so.height);
	data->texture.space_tex.img_ptr = mlx_xpm_file_to_image(data->mlx
		, "./images/sea.xpm"
		, &data->texture.space_tex.width
		, &data->texture.space_tex.height);
	data->texture.wall_tex.img_ptr = mlx_xpm_file_to_image(data->mlx
		, "./images/map_wall.xpm"
		, &data->texture.wall_tex.width
		, &data->texture.wall_tex.height);
	data->texture.floor_tex.img_ptr = mlx_xpm_file_to_image(data->mlx
		, "./images/floor.xpm"
		, &data->texture.floor_tex.width
		, &data->texture.floor_tex.height);
	data->texture.location_icon.img_ptr = mlx_xpm_file_to_image(data->mlx
		, "./images/location_icon.xpm"
		, &data->texture.location_icon.width
		, &data->texture.location_icon.height);
	data->texture.triangle_icon.img_ptr = mlx_xpm_file_to_image(data->mlx
		, "./images/triangle_icon.xpm"
		, &data->texture.triangle_icon.width
		, &data->texture.triangle_icon.height);
	data->texture.door_ea.img_ptr = mlx_xpm_file_to_image(data->mlx
		, "./images/door_h.xpm"
		, &data->texture.door_ea.width
		, &data->texture.door_ea.height);
	data->texture.door_we.img_ptr = mlx_xpm_file_to_image(data->mlx
		, "./images/door_h.xpm"
		, &data->texture.door_we.width
		, &data->texture.door_we.height);
	data->texture.door_no.img_ptr = mlx_xpm_file_to_image(data->mlx
		, "./images/door.xpm"
		, &data->texture.door_no.width
		, &data->texture.door_no.height);
	data->texture.door_so.img_ptr = mlx_xpm_file_to_image(data->mlx
		, "./images/door.xpm"
		, &data->texture.door_so.width
		, &data->texture.door_so.height);
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
	data->texture.location_icon.addr = mlx_get_data_addr(data->texture.location_icon.img_ptr
	, &data->texture.location_icon.bits_per_pixel
	, &data->texture.location_icon.line_length
	, &data->texture.location_icon.endian);
	data->texture.triangle_icon.addr = mlx_get_data_addr(data->texture.triangle_icon.img_ptr
	, &data->texture.triangle_icon.bits_per_pixel
	, &data->texture.triangle_icon.line_length
	, &data->texture.triangle_icon.endian);
	data->texture.door_ea.addr = mlx_get_data_addr(data->texture.door_ea.img_ptr
	, &data->texture.door_ea.bits_per_pixel
	, &data->texture.door_ea.line_length
	, &data->texture.door_ea.endian);
	data->texture.door_we.addr = mlx_get_data_addr(data->texture.door_we.img_ptr
	, &data->texture.door_we.bits_per_pixel
	, &data->texture.door_we.line_length
	, &data->texture.door_we.endian);
	data->texture.door_no.addr = mlx_get_data_addr(data->texture.door_no.img_ptr
	, &data->texture.door_no.bits_per_pixel
	, &data->texture.door_no.line_length
	, &data->texture.door_no.endian);
	data->texture.door_so.addr = mlx_get_data_addr(data->texture.door_so.img_ptr
	, &data->texture.door_so.bits_per_pixel
	, &data->texture.door_so.line_length
	, &data->texture.door_so.endian);
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
	data->open_door = 0;
	screen_init(data, img, map_img);
	data->trap_start.x = (SCREEN_WIDTH / 2) - (data->map_screen_width / 2);
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
	/*
		dbg
	*/
	data->dbg.win = mlx_new_window(data->mlx, data->map_screen_width
		, data->map_screen_height, "DBG cub3D");
	data->dbg.img.img_ptr = mlx_new_image(data->mlx, data->map_screen_width,
			data->map_screen_height);
	
	data->dbg.img.addr = mlx_get_data_addr(data->dbg.img.img_ptr, &data->dbg.img.bits_per_pixel,
			&data->dbg.img.line_length, &data->dbg.img.endian);
	/*
		dbg
	*/
	raycasting(data);
	listening_act(data);
	mlx_key_hook(data->win, key_hook, (void *) data);
	mlx_loop(data->mlx);
	return (0);
}
