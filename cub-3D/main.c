/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:30:57 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/04 11:55:01 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./pars/parsing.h"
# include "./graph/graph.h"
# include "./common/common.h"
# include "./event/event.h"
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>

int	main(int c, char **v)
{
	t_data *data;
	t_minimap mini_map;
	t_img img;

	if (c != 2)
		return (1);
	data = check_and_filling(v[1]);
	if (!data)
		return (1);
	data->mlx = mlx_init();
    if (!data->mlx)
    {
		print_error("mlx", "mlx_init() failed");
		ft_free_data(&data);
        return (1);
    }
	data->win = mlx_new_window(data->mlx, (data->map_width * TILE_SIZE)
		, (data->map_height * TILE_SIZE), "Cub 3D");
	mini_map.screen_height = data->map_height * MINIMAP_TILS;
	mini_map.screen_width = data->map_width * MINIMAP_TILS;
	data->mini_map = &mini_map;
	data->texture.img_ea.img_ptr = mlx_xpm_file_to_image(data->mlx, data->texture.east, &data->texture.width, &data->texture.height);
	data->texture.img_we.img_ptr = mlx_xpm_file_to_image(data->mlx, data->texture.west, &data->texture.width, &data->texture.height);
	data->texture.img_no.img_ptr = mlx_xpm_file_to_image(data->mlx, data->texture.north, &data->texture.width, &data->texture.height);
	data->texture.img_so.img_ptr = mlx_xpm_file_to_image(data->mlx, data->texture.south, &data->texture.width, &data->texture.height);
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
	img.img_ptr = mlx_new_image(data->mlx, data->screen_width,
			data->screen_height);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	data->img = &img;
	raycasting(data);
	listening_act(data);
	mlx_key_hook(data->win, key_hook, (void *) data);
	mlx_loop(data->mlx);
	return (0);
}


