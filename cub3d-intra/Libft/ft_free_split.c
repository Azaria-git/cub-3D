/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:20:32 by aravelom          #+#    #+#             */
/*   Updated: 2025/07/04 09:25:22 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **split)
{
	ssize_t	y;

	y = 0;
	if (split == NULL)
		return ;
	while (split[y])
	{
		free(split[y]);
		y++;
	}
	free(split);
}
