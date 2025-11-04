/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:30:18 by marrandr          #+#    #+#             */
/*   Updated: 2025/10/24 16:31:37 by aravelom         ###   ########.fr       */
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

static	size_t	count_len(char const *str, char sep, unsigned int index)
{
	size_t	count;

	count = 0;
	while (str[index] && str[index] != sep)
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

static int	count_sep(char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == sep)
			count++;
		i++;
	}
	return (count);
}

char	**ft_strsplit(char *s, char c, int i)
{
	int				len;
	int				word;
	char			**res;
	unsigned int	index;

	i = 0;
	index = 0;
	word = ft_count_word(s, c) + count_sep(s, c);
	res = ft_calloc((word + 2), sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (i < word)
	{
		while (s[index] && s[index] == c)
			res[i++] = ft_substr(s, index++, 1);
		len = count_len(s, c, index);
		res[i] = ft_substr(s, index, len);
		if (check_or_free(res, i))
			return (NULL);
		index = index + len;
		i++;
	}
	res[i] = NULL;
	return (res);
}
