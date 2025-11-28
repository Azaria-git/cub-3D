/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 07:14:24 by aravelom          #+#    #+#             */
/*   Updated: 2025/03/17 13:30:30 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*ptr;
	size_t		tot_size;

	ptr = NULL;
	tot_size = size * nmemb;
	ptr = (char *) malloc(tot_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, tot_size);
	return ((void *)ptr);
}
