/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 08:15:23 by aravelom          #+#    #+#             */
/*   Updated: 2025/03/12 07:44:06 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elem_last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	elem_last = ft_lstlast(*lst);
	elem_last->next = new;
}
