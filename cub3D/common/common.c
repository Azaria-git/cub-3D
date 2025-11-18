/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:25:26 by aravelom          #+#    #+#             */
/*   Updated: 2025/10/27 15:14:30 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "common.h"

void	print_error(char *intro, char *desc)
{
	write(2, "Error\n", 6);
	write(2, intro, ft_strlen(intro));
	write(2, ": ", 2);
	write(2, desc, ft_strlen(desc));
	write(2, "\n", 1);
}

double deg_to_rad(double deg)
{
    return (deg * (PI / 180.0));
}

void ft_free_data(t_data **data)
{
	if (!data || !(*data))
		return ;
	if ((*data)->map)
		ft_free_split((*data)->map);
	if ((*data)->mlx && (*data)->mlx && (*data)->win)
		mlx_destroy_window((*data)->mlx, (*data)->win);
	if ((*data)->mlx && (*data)->mlx)
	{
		mlx_destroy_display((*data)->mlx);
		free((*data)->mlx);
	}
	if ((*data)->texture.east)
		free ((*data)->texture.east);
	if ((*data)->texture.north)
		free ((*data)->texture.north);
	if ((*data)->texture.south)
		free ((*data)->texture.south);
	if ((*data)->texture.west)
		free ((*data)->texture.west);
	free (*data);
	(*data) = NULL;
}
