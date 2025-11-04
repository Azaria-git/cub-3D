/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 07:16:29 by aravelom          #+#    #+#             */
/*   Updated: 2025/03/17 13:33:11 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int n)
{
	int	size;

	if (n == -2147483648)
		return (11);
	size = 0;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	size++;
	return (size);
}

static void	fill_tab(char *str_i, int n, int size, int stat)
{
	while (n >= 10)
	{
		str_i[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	str_i[size] = n + '0';
	if (stat)
		str_i[10] = '8';
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str_i;
	int		stat;

	size = count_len(n);
	stat = 0;
	str_i = NULL;
	str_i = malloc(sizeof(char) * (size + 1));
	if (str_i == NULL)
		return (str_i);
	str_i[size] = '\0';
	size--;
	if (n == -2147483648)
	{
		n += 1;
		stat = 1;
	}
	if (n < 0)
	{
		*str_i = '-';
		n *= -1;
	}
	fill_tab(str_i, n, size, stat);
	return (str_i);
}
