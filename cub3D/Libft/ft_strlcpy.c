/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:53:12 by aravelom          #+#    #+#             */
/*   Updated: 2025/03/12 10:33:48 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if ((src_len + 1) <= size)
		ft_memcpy(dst, src, src_len + 1);
	if ((src_len + 1) > size)
	{
		ft_memcpy(dst, src, size);
		dst[size - 1] = '\0';
	}
	return (src_len);
}
