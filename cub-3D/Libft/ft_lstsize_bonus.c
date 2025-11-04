/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:13:29 by aravelom          #+#    #+#             */
/*   Updated: 2025/03/10 10:20:40 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*l;

	i = 1;
	l = lst;
	if (l == NULL)
		return (0);
	while (l->next != NULL)
	{
		l = l->next;
		i++;
	}
	return (i);
}
