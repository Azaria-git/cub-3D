/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:16:13 by aravelom          #+#    #+#             */
/*   Updated: 2025/03/11 10:55:38 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = ft_strlen(s) + 1;
	while (len)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		len--;
	}
	return (0);
}
