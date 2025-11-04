/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:24:42 by marrandr          #+#    #+#             */
/*   Updated: 2025/10/24 16:31:32 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./parsing.h"

int	ft_space_and_digit(int s)
{
	if (s == ' ')
		return (1);
	if (s >= '0' && s <= '9')
		return (1);
	else
		return (0);
}

int	ft_lendigit(char *s)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i] && s[i] == ' ')
		i++;
	while (s[i] && s[i] == '0')
		i++;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			count++;
		i++;
	}
	return (count);
}

int	check_type_file(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (i <= 4 || (i > 4 && (path[0] == '.' && i > 5 && path[1] != '/')))
	{
		put_error("file", "bad extension (.cub) or cache file");
		return (0);
	}
	if (path[i - 1] != 'b' || path[i - 2] != 'u'
		|| path[i - 3] != 'c' || path[i - 4] != '.')
	{
		put_error("file", "bad extension (.cub) or cache file");
		return (0);
	}
	return (1);
}

char	*skip_first_word(char *line, char *w)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	j = 0;
	if (w && line[i] && w[0] == line[i])
		while (w[j] && line[i + j] && w[j] == line[i + j])
			j++;
	else
		return (NULL);
	if (j && !w[j])
	{
		while (line[i + j] && line[i + j] == ' ')
			j++;
		return (line + i + j);
	}
	else
		return (NULL);
}

int	ft_atoi_strict(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i])
		return (-1);
	return (sign * res);
}
