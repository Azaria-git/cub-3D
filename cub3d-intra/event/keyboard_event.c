/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:48:37 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/26 15:59:56 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./event.h"

// static void cam_trapeze(int keycode, t_data *data)
// {
// 	float cam_speed;
	
// 	cam_speed = 0.15; // vitesse en cases
// 	if (keycode == K_LEFT)
// 		data->cam_x -= cam_speed;
// 	if (keycode == K_RIGHT)
// 		data->cam_x += cam_speed;
// 	if (keycode == K_UP)
// 		data->cam_y -= cam_speed;
// 	if (keycode == K_DOWN)
// 		data->cam_y += cam_speed;

// 	// Clamping pour rester dans la map
// 	if (data->cam_x < 0)
// 		data->cam_x = 0;
// 	if (data->cam_y < 0)
// 		data->cam_y = 0;
// 	float max_cam_x = data->map_width - (data->trap_w / (float)TILE_SIZE);
// 	float max_cam_y = data->map_height - (data->trap_h / (float)TILE_SIZE);
// 	if (data->cam_x > max_cam_x)
// 		data->cam_x = max_cam_x;
// 	if (data->cam_y > max_cam_y)
// 		data->cam_y = max_cam_y;
// 	// draw_trapeze_map(data);
// }

int	ft_react_click_button_x(void *param)
{
	t_data	*data;

	data = (t_data *) param;
	mlx_destroy_image(data->mlx, data->img->img_ptr);
	ft_free_data(&data);
	exit(0);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *) param;
	if (keycode == ESC)
	{
		mlx_destroy_image(data->mlx, data->img->img_ptr);
		ft_free_data(&data);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == K_SPACE)
	{
		data->show_trapeze = !data->show_trapeze;
		raycasting(data);
	}
	else if (keycode == 'o')
		data->open_door = 1;
	else if (keycode == '0' && data->open_door)
		data->open_door = 0;
	return (0);
}
