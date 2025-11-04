/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:13:15 by marrandr          #+#    #+#             */
/*   Updated: 2025/10/29 15:41:57 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./event.h"

void	listening_act(t_data *d)
{
	mlx_hook(d->win, 2, 1L<<0, event_move, (void *) d);
	//mlx_key_hook(d->win, event_move, (void *) d);
}
