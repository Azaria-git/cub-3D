/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:28:15 by aravelom          #+#    #+#             */
/*   Updated: 2025/10/28 07:43:22 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include "../Libft/libft.h"
# include "../struct/data.h"
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# define PI		3.14159265358979323846
void	print_error(char *intro, char *desc);
void	ft_free_data(t_data **data);
double deg_to_rad(double deg);

#endif
