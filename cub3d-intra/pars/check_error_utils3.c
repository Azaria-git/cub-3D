/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrandr <marrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 08:56:13 by marrandr          #+#    #+#             */
/*   Updated: 2025/11/27 11:45:04 by marrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_ischar(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	ft_isspace(char c)
{
	if (c == 32 || (c > 8 && c < 14))
		return (1);
	else
		return (0);
}

static	size_t	count_len(char const *str, char *sep, unsigned int index)
{
	size_t	count;

	count = 0;
	while (str[index] && !ft_strchr(sep, str[index]))
	{
		count++;
		index++;
	}
	return (count);
}

static int	ft_free_all(char **res, int i)
{
	if (res[i] != NULL)
		return (0);
	while (i >= 0)
		free (res[i--]);
	free (res);
	return (1);
}

char	**ft_split_exam(char const *s, char *sep)
{
	char			**res;
	size_t			word;
	unsigned int	index;
	size_t			len;
	size_t			i;

	i = 0;
	index = 0;
	word = ft_count_word(s, sep);
	res = (char **)malloc ((word + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (i < word)
	{
		while (s[index] && ft_strchr(sep, s[index]))
			index++;
		len = count_len(s, sep, index);
		res[i] = ft_substr(s, index, len);
		if (ft_free_all(res, i))
			return (NULL);
		index = index + len + 1;
		i++;
	}
	res[i] = NULL;
	return (res);
}