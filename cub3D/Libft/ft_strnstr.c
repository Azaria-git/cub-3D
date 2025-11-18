/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:44:16 by aravelom          #+#    #+#             */
/*   Updated: 2025/03/12 15:29:02 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (*little == '\0')
		return ((char *)big);
	while (*big && len)
	{
		if (*big == *little && (ft_strlen(little) <= len))
		{
			if (ft_strncmp(big, little, ft_strlen(little)) == 0)
				return ((char *)big);
		}
		len--;
		big++;
	}
	return (0);
}
