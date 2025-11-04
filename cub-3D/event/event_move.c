/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:00:07 by marrandr          #+#    #+#             */
/*   Updated: 2025/11/04 09:19:55 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./event.h"

static int	double_to_int(double nb)
{
	int	a;

	a = nb;
	return (nb + (0.8 <= (double)((int)(nb) - a)));
}

static void	move_backwards(t_data *data)
{
	double	x;
	double	y;

	x = data->player.pos_x - (cos(data->player.orientation) * STEP);
	y = data->player.pos_y - (sin(data->player.orientation) * STEP);
	if (data->map[double_to_int(y)][double_to_int(x)] != '1')
	{
		data->player.pos_x -= (cos(data->player.orientation) * STEP);
		data->player.pos_y -= (sin(data->player.orientation) * STEP);
	}
}

static void	move_forwards(t_data *data)
{
	double	x;
	double	y;

	x = data->player.pos_x + (cos(data->player.orientation) * STEP);
	y = data->player.pos_y + (sin(data->player.orientation) * STEP);
	if (data->map[double_to_int(y)][double_to_int(x)] != '1')
	{
		data->player.pos_x += (cos(data->player.orientation) * STEP);
		data->player.pos_y += (sin(data->player.orientation) * STEP);
	}
}
/*
static void	move_left(t_data *data)
{
	double	x;
	double	y;

	if (data->player.orientation == deg_to_rad(270) || data->player.orientation == deg_to_rad(90))
	{
		x = data->player.pos_x + (cos(data->player.orientation) * STEP);
		y = data->player.pos_y;
	}
	else if (data->player.orientation == deg_to_rad(0) || data->player.orientation == deg_to_rad(180))
	{
		x = data->player.pos_x ;
		y = data->player.pos_y - (sin(data->player.orientation) * STEP);
	}
	else
	{
		x = data->player.pos_x + (cos(data->player.orientation) * STEP);
		y = data->player.pos_y - (sin(data->player.orientation) * STEP);
	}
	if (data->map[double_to_int(y)][double_to_int(x)] != '1')
	{
		data->player.pos_x += (cos(data->player.orientation) * STEP);
		data->player.pos_y -= (sin(data->player.orientation) * STEP);
	}
}

static void	move_right(t_data *data)
{
	double	x;
	double	y;

	printf("%lf\n", data->player.orientation);
	if (data->player.orientation == deg_to_rad(270) || data->player.orientation == deg_to_rad(90))
	{
		x = data->player.pos_x - (cos(data->player.orientation) * STEP);
		y = data->player.pos_y;
	}
	else if (data->player.orientation == deg_to_rad(0) || data->player.orientation == deg_to_rad(180))
	{
		x = data->player.pos_x;
		y = data->player.pos_y + (sin(data->player.orientation) * STEP);
	}
	else
	{
		x = data->player.pos_x - (cos(data->player.orientation) * STEP);
		y = data->player.pos_y + (sin(data->player.orientation) * STEP);
	}
	if (data->map[double_to_int(y)][double_to_int(x)] != '1')
	{
		data->player.pos_x -= (cos(data->player.orientation) * STEP);
		data->player.pos_y += (sin(data->player.orientation) * STEP);
	}
}
*/

int	event_move(int k_code, void *p)
{
	t_data	*data;

	data = (t_data *)p;
	data->player.map_y = (int)data->player.pos_y;
	data->player.map_x = (int)data->player.pos_x;
	if ((k_code == K_BACKWARDS || k_code == K_DOWN)
		&& ((data->map_height -1) != (int)data->player.map_y))
		move_backwards(data);
	else if ((k_code == K_FORWARD || k_code == K_UP) && data->player.pos_y > 1)
		move_forwards(data);
	/*
	else if (k_code == K_TO_LEFT && data->player.pos_x > 1)
		move_left(data);
	else if (k_code == K_TO_RIGHT
		&& ((data->map_width -1) != (int)data->player.map_x))
		move_right(data);
	*/
	data->player.map_y = (int)data->player.pos_y;
	data->player.map_x = (int)data->player.pos_x;
	event_rotate(k_code, p);
	raycasting(data);
	return (0);
}
