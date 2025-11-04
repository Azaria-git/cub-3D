/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_delim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:09:37 by aravelom          #+#    #+#             */
/*   Updated: 2025/07/01 20:54:31 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_delim(const char *str, const char *delim)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str && ft_strchr(delim, *str))
		i++;
	return (i);
}
