/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 08:10:45 by aravelom          #+#    #+#             */
/*   Updated: 2025/03/12 07:20:37 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	size;

	if (lst == NULL)
		return (lst);
	size = ft_lstsize(lst);
	while (size)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
		size--;
	}
	return (lst);
}
