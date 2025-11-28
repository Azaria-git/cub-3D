/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:36:38 by aravelom          #+#    #+#             */
/*   Updated: 2025/03/12 15:25:43 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*unsigned_s1;
	unsigned char	*unsigned_s2;

	if (n == 0)
		return (0);
	unsigned_s1 = (unsigned char *) s1;
	unsigned_s2 = (unsigned char *) s2;
	while (n != 0)
	{
		if (!(*unsigned_s1 == *unsigned_s2))
			return (*unsigned_s1 - *unsigned_s2);
		unsigned_s1++;
		unsigned_s2++;
		n--;
	}
	return (*(unsigned_s1 - 1) - *(unsigned_s2 - 1));
}
