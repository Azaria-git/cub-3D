/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:39:31 by aravelom          #+#    #+#             */
/*   Updated: 2025/05/19 08:47:05 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*nb_toexa_char(unsigned long long arg)
{
	char				*ret;
	size_t				size;
	unsigned long long	nb_tmp;
	char				*ox;

	size = 0;
	ox = "0123456789abcdef";
	ret = NULL;
	nb_tmp = arg;
	while (nb_tmp)
	{
		size ++;
		nb_tmp /= 16;
	}
	ret = (char *) malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	ret[size] = '\0';
	while (arg)
	{
		size--;
		ret[size] = ox[arg % 16];
		arg /= 16;
	}
	return (ret);
}

size_t	count_size(long long arg)
{
	size_t	ret;

	ret = 0;
	if (arg < 0)
	{
		ret++;
		arg *= -1;
	}
	while (arg)
	{
		ret++;
		arg /= 10;
	}
	return (ret);
}

char	*nb_tolong_char(long long arg)
{
	char		*ret;
	size_t		size;

	size = count_size(arg);
	ret = NULL;
	ret = (char *) malloc(sizeof(char) * (size + 1));
	if (ret != NULL)
	{
		if (arg < 0)
		{
			arg *= -1;
			ret[0] = '-';
		}
		ret[size] = '\0';
		while (arg)
		{
			size--;
			ret[size] = (arg % 10) + '0';
			arg /= 10;
		}
	}
	return (ret);
}

int	p_hex(const char *l, va_list v)
{
	unsigned int	arg;
	char			*string_arg;
	int				ret;

	string_arg = NULL;
	ret = 0;
	arg = (unsigned int) va_arg(v, unsigned int);
	if (arg == 0)
		return ((int) write(1, "0", 1));
	string_arg = nb_toexa_char(arg);
	if (string_arg == NULL)
		return (0);
	if (*l == 'X')
	{
		while (string_arg[ret])
		{
			if (string_arg[ret] >= 'a' && string_arg[ret] <= 'z')
				string_arg[ret] = string_arg[ret] - 32;
			ret++;
		}
	}
	ret = (int) write(1, string_arg, ft_strlen(string_arg));
	free(string_arg);
	return (ret);
}
