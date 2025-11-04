/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:57:52 by aravelom          #+#    #+#             */
/*   Updated: 2025/05/26 10:22:59 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(char const *s, char c)
{
	int	stat;
	int	i;

	stat = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && stat == 0)
		{
			i++;
			stat = 1;
		}
		if (*s == c)
			stat = 0;
		s++;
	}
	return (i);
}

static char	*new_s(char const *s, char c)
{
	char	*new;
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	new = (char *) malloc(sizeof(char) * (i + 1));
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s, i);
	new[i] = '\0';
	return (new);
}

static void	free_s(char **str_split, int i)
{
	i--;
	while (i >= 0)
	{
		free(str_split[i]);
		i--;
	}
}

static void	fill_split(char **str_split, char const *s, char c)
{
	int	stat;
	int	i;

	stat = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && stat == 0)
		{
			str_split[i] = new_s(s, c);
			if (str_split[i] == NULL)
			{
				free_s(str_split, i);
				return ;
			}
			stat = 1;
			i++;
		}
		if (*s == c)
			stat = 0;
		s++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**str_split;

	if (s == NULL)
		return (NULL);
	size = count_size(s, c);
	str_split = NULL;
	str_split = (char **) malloc(sizeof(char *) * (size + 1));
	if (str_split == NULL)
		return (NULL);
	str_split[size] = NULL;
	fill_split(str_split, s, c);
	return (str_split);
}
