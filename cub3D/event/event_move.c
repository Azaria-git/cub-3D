/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:00:07 by marrandr          #+#    #+#             */
/*   Updated: 2025/11/13 12:18:07 by marrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./event.h"

static void	move_backwards(t_data *data)
{
	double	x;
	double	y;
	double	temp;

	x = data->player.pos_x;
	temp = data->player.pos_y - (sin(data->player.orientation) * STEP);
	if (data->map[(int)(temp + SCAL)][(int)(x)] != '1'
		&& data->map[(int)(temp - SCAL)][(int)(x)] != '1')
		data->player.pos_y = temp;
	y = data->player.pos_y;
	temp = data->player.pos_x - (cos(data->player.orientation) * STEP);
	if (data->map[(int)y][(int)(temp + SCAL)] != '1'
		&& data->map[(int)y][(int)(temp - SCAL)] != '1')
		data->player.pos_x = temp;
}

static void	move_forwards(t_data *data)
{
	double	x;
	double	y;
	double	temp;

	x = data->player.pos_x;
	temp = data->player.pos_y + (sin(data->player.orientation) * STEP);
	if (data->map[(int)(temp + SCAL)][(int)(x)] != '1' 
		&& data->map[(int)(temp - SCAL)][(int)(x)] != '1')
		data->player.pos_y = temp;
	y = data->player.pos_y;
	temp = data->player.pos_x + (cos(data->player.orientation) * STEP);
	if (data->map[(int)(y)][(int)(temp + SCAL)] != '1' 
		&& data->map[(int)(y)][(int)(temp - SCAL)] != '1')
		data->player.pos_x = temp;
}

static void	move_right(t_data *data)
{
	double	x;
	double	y;
	double	temp;

	y = data->player.pos_y;
	temp = data->player.pos_x - (sin(data->player.orientation) * STEP1);
	if (data->map[(int)(y)][(int)(temp + SCAL)] != '1'
		&& data->map[(int)(y)][(int)(temp - SCAL)] != '1')
		data->player.pos_x = temp;
	x = data->player.pos_x;
	temp = data->player.pos_y + (cos(data->player.orientation) * STEP1);
	if (data->map[(int)(temp + SCAL)][(int)(x)] != '1'
		&& data->map[(int)(temp - SCAL)][(int)(x)] != '1')
		data->player.pos_y = temp;
}

static void	move_left(t_data *data)
{
	double	x;
	double	y;
	double	temp;

	y = data->player.pos_y;
	temp = data->player.pos_x + (sin(data->player.orientation) * STEP1);
	if (data->map[(int)(y)][(int)(temp + SCAL)] != '1' 
		&& data->map[(int)(y)][(int)(temp - SCAL)] != '1')
		data->player.pos_x = temp;
	x = data->player.pos_x;
	temp = data->player.pos_y - (cos(data->player.orientation) * STEP1);
	if (data->map[(int)(temp + SCAL)][(int)(x)] != '1' 
		&& data->map[(int)(temp - SCAL)][(int)(x)] != '1')
		data->player.pos_y = temp;
}

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
	else if (k_code == K_TO_LEFT && data->player.pos_x > 1)
		move_left(data);
	else if (k_code == K_TO_RIGHT
		&& ((data->map_width -1) != (int)data->player.map_x))
		move_right(data);
	data->player.map_y = (int)data->player.pos_y;
	data->player.map_x = (int)data->player.pos_x;
	event_rotate(k_code, p);
	raycasting(data);
	return (0);
}
