/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrandr <marrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:30:18 by marrandr          #+#    #+#             */
/*   Updated: 2025/11/27 12:29:07 by marrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./parsing.h"

int	count_word_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return (0);
	while (split[i])
		i++;
	return (i);
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

static int	check_or_free(char **res, int i)
{
	if (res[i] != NULL)
		return (0);
	while (i >= 0)
		free (res[i--]);
	free (res);
	return (1);
}

static int	count_sep(char *str, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_strchr(sep, str[i]))
			count++;
		i++;
	}
	return (count);
}

char	**ft_strsplit(char *s, char *sep, int i, int j)
{
	int				len;
	int				word;
	char			**res;
	unsigned int	index;

	index = 0;
	word = ft_count_word(s, sep) + count_sep(s, sep);
	res = ft_calloc((word + 1), sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (++i < word)
	{
		len = count_len(s, sep, index);
		res[i] = ft_substr(s, index, len);
		if (check_or_free(res, i))
			return (NULL);
		index = index + len;
		j = 0;
		while (s[index + j] && ft_strchr(sep, s[index + j]))
			j++;
		if (j > 0)
			res[++i] = ft_substr(s, index++, j);
	}
	res[i] = NULL;
	return (res);
}
