/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:39:09 by aravelom          #+#    #+#             */
/*   Updated: 2025/03/10 10:43:18 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	int		size;

	first = NULL;
	if (lst == NULL)
		return (NULL);
	size = ft_lstsize(lst);
	first = ft_lstnew(f(lst->content));
	if (first == NULL)
		return (NULL);
	while (size - 1)
	{
		lst = lst->next;
		new = NULL;
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		size--;
	}
	return (first);
}
