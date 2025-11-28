/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:00:07 by marrandr          #+#    #+#             */
/*   Updated: 2025/11/28 14:32:21 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./event.h"

static void	move_backwards(t_data *data)
{
	t_coord	pxl;

	pxl.x = data->player.pxl_pos.x - (data->player.dir_x * STEP);
	pxl.y = data->player.pxl_pos.y;
	if (data->map[pxl_to_int(pxl.y)][pxl_to_int(pxl.x + SCAL)] != '1'
		&& data->map[pxl_to_int(pxl.y)][pxl_to_int(pxl.x - SCAL)] != '1')
		data->player.pxl_pos.x = pxl.x;
	pxl.y = data->player.pxl_pos.y - (data->player.dir_y * STEP);
	pxl.x = data->player.pxl_pos.x;
	if (data->map[pxl_to_int(pxl.y + SCAL)][pxl_to_int(pxl.x)] != '1'
		&& data->map[pxl_to_int(pxl.y - SCAL)][pxl_to_int(pxl.x)] != '1')
		data->player.pxl_pos.y = pxl.y;
}

static void	move_forwards(t_data *data)
{
	t_coord	pxl;

	pxl.x = data->player.pxl_pos.x + (data->player.dir_x * STEP);
	pxl.y = data->player.pxl_pos.y;
	if (data->map[pxl_to_int(pxl.y)][pxl_to_int(pxl.x + SCAL)] != '1'
		&& data->map[pxl_to_int(pxl.y)][pxl_to_int(pxl.x - SCAL)] != '1')
		data->player.pxl_pos.x = pxl.x;
	pxl.y = data->player.pxl_pos.y + (data->player.dir_y * STEP);
	pxl.x = data->player.pxl_pos.x;
	if (data->map[pxl_to_int(pxl.y + SCAL)][pxl_to_int(pxl.x)] != '1'
		&& data->map[pxl_to_int(pxl.y - SCAL)][pxl_to_int(pxl.x)] != '1')
		data->player.pxl_pos.y = pxl.y;
}

static void	move_right(t_data *data)
{
	t_coord	pxl;

	pxl.x = data->player.pxl_pos.x - (data->player.dir_y * STEP1);
	pxl.y = data->player.pxl_pos.y;
	if (data->map[pxl_to_int(pxl.y)][pxl_to_int(pxl.x + SCAL)] != '1'
		&& data->map[pxl_to_int(pxl.y)][pxl_to_int(pxl.x - SCAL)] != '1')
		data->player.pxl_pos.x = pxl.x;
	pxl.y = data->player.pxl_pos.y + (data->player.dir_x * STEP1);
	pxl.x = data->player.pxl_pos.x;
	if (data->map[pxl_to_int(pxl.y + SCAL)][pxl_to_int(pxl.x)] != '1'
		&& data->map[pxl_to_int(pxl.y - SCAL)][pxl_to_int(pxl.x)] != '1')
		data->player.pxl_pos.y = pxl.y;
}

static void	move_left(t_data *data)
{
	t_coord	pxl;

	pxl.x = data->player.pxl_pos.x + (data->player.dir_y * STEP1);
	pxl.y = data->player.pxl_pos.y;
	if (data->map[pxl_to_int(pxl.y)][pxl_to_int(pxl.x + SCAL)] != '1'
		&& data->map[pxl_to_int(pxl.y)][pxl_to_int(pxl.x - SCAL)] != '1')
		data->player.pxl_pos.x = pxl.x;
	pxl.y = data->player.pxl_pos.y - (data->player.dir_x * STEP1);
	pxl.x = data->player.pxl_pos.x;
	if (data->map[pxl_to_int(pxl.y + SCAL)][pxl_to_int(pxl.x)] != '1'
		&& data->map[pxl_to_int(pxl.y - SCAL)][pxl_to_int(pxl.x)] != '1')
		data->player.pxl_pos.y = pxl.y;
}

int	event_move(int k_code, void *p)
{
	t_data	*data;

	data = (t_data *)p;
	if ((k_code == K_BACKWARDS || k_code == K_DOWN))
		move_backwards(data);
	else if ((k_code == K_FORWARD || k_code == K_UP))
		move_forwards(data);
	else if (k_code == K_TO_LEFT)
		move_left(data);
	else if (k_code == K_TO_RIGHT)
		move_right(data);
	event_rotate(k_code, p);
	raycasting(data);
	return (0);
}
