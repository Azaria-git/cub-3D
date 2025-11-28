/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:20:52 by marrandr          #+#    #+#             */
/*   Updated: 2025/11/28 14:31:33 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./event.h"

int	pxl_to_int(int pxl)
{
	return (pxl / TILE_SIZE);
}

static void	update_data(t_data *data)
{
	data->player.dir_x = cos(data->player.orientation);
	data->player.dir_y = sin(data->player.orientation);
}

int	event_rotate(int k_code, void *p)
{
	t_data	*data;

	data = (t_data *)p;
	if (k_code == K_LEFT)
	{
		if (data->player.orientation == deg_to_rad(0))
			data->player.orientation = deg_to_rad(360);
		data->player.orientation -= deg_to_rad(DEG_STEP);
		update_data(data);
		raycasting(data);
	}
	if (k_code == K_RIGHT)
	{
		if (data->player.orientation == deg_to_rad(360))
			data->player.orientation = deg_to_rad(0);
		data->player.orientation += deg_to_rad(DEG_STEP);
		update_data(data);
	}
	return (0);
}
