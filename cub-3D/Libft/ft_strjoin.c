/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:34:42 by aravelom          #+#    #+#             */
/*   Updated: 2025/07/01 20:42:45 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_join;

	str_join = NULL;
	str_join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str_join != NULL)
	{
		*str_join = '\0';
		ft_strcpy(str_join, s1);
		return (ft_strcat(str_join, s2));
	}
	return (str_join);
}
