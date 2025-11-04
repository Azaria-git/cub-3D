/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:16:35 by aravelom          #+#    #+#             */
/*   Updated: 2025/07/23 10:24:06 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(char **list, int c)
{
	char	*string;
	ssize_t	len;
	ssize_t	y;

	y = 0;
	len = 0;
	if (!list || !list[0])
		return (NULL);
	while (list[y])
		len += ft_strlen_gnl(list[y++]);
	if (c != 0)
		string = (char *)ft_calloc(len + y, 1);
	else
		string = (char *)ft_calloc(len + 1, 1);
	if (string == NULL)
		return (NULL);
	y = 0;
	while (list[y])
	{
		ft_strcat(string, list[y]);
		if (list[y + 1] && c != 0)
			ft_strcat(string, (char *)&c);
		y++;
	}
	return (string);
}
