/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:10:29 by aravelom          #+#    #+#             */
/*   Updated: 2025/07/01 20:52:28 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nw_lst;

	nw_lst = NULL;
	nw_lst = (t_list *)malloc(sizeof(t_list));
	if (nw_lst == NULL)
		return (nw_lst);
	nw_lst->content = content;
	nw_lst->next = NULL;
	return (nw_lst);
}
