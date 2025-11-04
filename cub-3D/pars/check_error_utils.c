/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:34:31 by marrandr          #+#    #+#             */
/*   Updated: 2025/10/24 16:51:54 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./parsing.h"

void	put_error(char *source, char *info)
{
	write (2, "Error\nInvalid ", 14);
	if (source)
		write (2, source, ft_strlen(source));
	write (2, ": ", 2);
	if (info)
		write (2, info, ft_strlen(info));
	write(2, "\n", 1);
}

int	ft_is_f_loop(int (*f)(int), char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (f(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_word(char const *str, char sep)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != sep && (i == 0 || str[i - 1] == sep))
			count++;
		i++;
	}
	return (count);
}

void	ft_free_split(char **s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		free (s[i++]);
	free (s);
}
