/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:44:12 by aravelom          #+#    #+#             */
/*   Updated: 2025/03/17 13:38:53 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_mapi;
	int		i;

	if (s == NULL)
		return (NULL);
	str_mapi = NULL;
	str_mapi = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str_mapi == NULL)
		return (str_mapi);
	i = 0;
	while (s[i] != '\0')
	{
		str_mapi[i] = (*f)(i, s[i]);
		i++;
	}
	str_mapi[i] = '\0';
	return (str_mapi);
}
