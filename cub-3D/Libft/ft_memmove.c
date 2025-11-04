/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:15:01 by aravelom          #+#    #+#             */
/*   Updated: 2025/03/11 09:28:32 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;

	to = (unsigned char *)dest;
	from = (unsigned char *)src;
	if (from == to)
		return (dest);
	if (to > from)
	{
		while (n != 0)
		{
			n--;
			*(to + n) = *(from + n);
		}
	}
	if (to < from)
		ft_memcpy(dest, src, n);
	return (dest);
}
