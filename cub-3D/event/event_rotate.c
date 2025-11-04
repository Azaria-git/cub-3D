/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:20:52 by marrandr          #+#    #+#             */
/*   Updated: 2025/10/29 16:35:09 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./event.h"

int	event_rotate(int k_code, void *p)
{
	t_data	*data;

	data = (t_data *)p;
	if (k_code == K_LEFT)
	{
		if (data->player.orientation == deg_to_rad(0) )
			data->player.orientation = deg_to_rad(360);
		data->player.orientation -= deg_to_rad(1);
		raycasting(data);
	}
	if (k_code == K_RIGHT)
	{
		if (data->player.orientation == deg_to_rad(360))
			data->player.orientation = deg_to_rad(0);
		data->player.orientation += deg_to_rad(1);
		raycasting(data);
	}
	return (0);
}
