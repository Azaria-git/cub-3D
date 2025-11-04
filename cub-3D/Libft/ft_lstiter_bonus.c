/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:52:32 by aravelom          #+#    #+#             */
/*   Updated: 2025/03/07 13:38:54 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;
	int		size;

	if (lst == NULL)
		return ;
	size = ft_lstsize(lst);
	while (size)
	{
		tmp = lst->next;
		(*f)(lst->content);
		lst = tmp;
		size--;
	}
}
