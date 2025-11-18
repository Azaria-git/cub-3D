/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 07:14:53 by aravelom          #+#    #+#             */
/*   Updated: 2025/05/14 07:17:23 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnbchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == (char) c)
			i++;
		s++;
	}
	return (i);
}
