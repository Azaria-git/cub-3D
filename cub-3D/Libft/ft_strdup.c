/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 07:48:26 by aravelom          #+#    #+#             */
/*   Updated: 2025/03/17 13:36:59 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str_dup;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	str_dup = NULL;
	str_dup = (char *) malloc(sizeof(char) * (len + 1));
	if (str_dup != NULL)
	{
		ft_memmove(str_dup, s, len);
		str_dup[len] = '\0';
		return (str_dup);
	}
	return (str_dup);
}
