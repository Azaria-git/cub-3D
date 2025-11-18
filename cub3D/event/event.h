/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:46:16 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/13 11:20:45 by marrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H
# define ESC 65307
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_UP 65362
# define K_DOWN 65364
# define STEP 0.1
# define SCAL 0.25
# define STEP1 0.09
# define K_FORWARD 'w'
# define K_BACKWARDS 's'
# define K_TO_LEFT 'a'
# define K_TO_RIGHT 'd'
# define NORTH 270
# define SOUTH 90
# define EAST 0
# define WEST 180

# include "../minilibx-linux/mlx.h"
# include "../struct/data.h"
# include "../common/common.h"
# include "../graph/graph.h"

int		key_hook(int keycode, void *param);
int		event_rotate(int keycode, void *param);
int		event_move(int k_code, void *p);
void	listening_act(t_data *d);

#endif
