/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:48:37 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/05 13:25:49 by marrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./event.h"

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
	return (0);
}
