/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:51:15 by aravelom          #+#    #+#             */
/*   Updated: 2025/07/21 13:08:43 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimall(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		count;

	if (!s1)
		return (NULL);
	i = 0;
	count = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]))
			count++;
		i++;
	}
	res = (char *) ft_calloc(i - count + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	count = 0;
	while (s1[++i])
	{
		if (!ft_strchr(set, s1[i]))
			res[count++] = s1[i];
	}
	return (res);
}
