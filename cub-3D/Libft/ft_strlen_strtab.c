/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_strtab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:17:54 by aravelom          #+#    #+#             */
/*   Updated: 2025/08/25 13:36:11 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_strlen_strtab(char **tab, char *delim)
{
	ssize_t	result;

	result = 0;
	if (!tab)
		return (0);
	while (tab[result] && tab[result] != delim)
		result++;
	return (result);
}
