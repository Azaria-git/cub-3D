/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:03:47 by aravelom          #+#    #+#             */
/*   Updated: 2025/05/12 08:49:21 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	if (s == NULL)
		return (0);
	if (s[0] == '\0')
		return (0);
	return (1 + ft_strlen_gnl(++s));
}

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen_gnl(s) + 1;
	while (len)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		len--;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str_join;
	int		i;

	str_join = NULL;
	str_join = (char *) malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	i = 0;
	if (str_join != NULL)
	{
		if (s1 != NULL)
		{
			while (s1[i])
			{
				str_join[i] = s1[i];
				i++;
			}
			free(s1);
		}
		if (s2 != NULL)
		{
			while (*s2)
				str_join[i++] = *s2++;
		}
		str_join[i] = '\0';
	}
	return (str_join);
}
