/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:59:35 by aravelom          #+#    #+#             */
/*   Updated: 2025/05/19 08:38:07 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	p_int(const char *l, va_list v)
{
	int			ret;
	long long	nb_int;
	char		*string_arg;

	nb_int = 0;
	if (*l == 'u')
		nb_int = (unsigned int) va_arg(v, unsigned int);
	else
		nb_int = (int) va_arg(v, int);
	if (nb_int == 0)
	{
		ret = (int) write(1, "0", 1);
		return (ret);
	}
	string_arg = nb_tolong_char(nb_int);
	if (string_arg == NULL)
		return (0);
	ret = (int) write(1, string_arg, ft_strlen(string_arg));
	free(string_arg);
	return (ret);
}

int	p_ptr(va_list v)
{
	int						ret;
	unsigned long long		cast_void;
	char					*string_arg;
	void					*ptr;

	ret = 0;
	ptr = (void *) va_arg(v, void *);
	if (ptr == NULL)
	{
		ret = (int) write(1, "(nil)", 5);
		return (ret);
	}
	cast_void = (unsigned long long) ptr;
	string_arg = NULL;
	string_arg = nb_toexa_char(cast_void);
	if (string_arg == NULL)
		return (0);
	ret = (int) write(1, "0x", 2);
	ret += (int) write(1, string_arg, ft_strlen(string_arg));
	free(string_arg);
	return (ret);
}

int	p_str(va_list v)
{
	int		ret;
	char	*string_arg;

	string_arg = NULL;
	string_arg = (char *) va_arg(v, char *);
	if (string_arg == NULL)
	{
		ret = (int) write(1, "(null)", 6);
		return (ret);
	}
	ret = (int) write(1, string_arg, ft_strlen(string_arg));
	return (ret);
}

int	print_arg(const char *l, va_list v)
{
	int		ret;
	char	arg_char;

	ret = 0;
	if (*l == 'x' || *l == 'X')
		ret = p_hex(l, v);
	else if (*l == 'u' || *l == 'd' || *l == 'i')
		ret = p_int(l, v);
	else if (*l == 's')
		ret = p_str(v);
	else if (*l == 'c')
	{
		arg_char = (char ) va_arg(v, int);
		ret = (int) write(1, &arg_char, 1);
	}
	else if (*l == 'p')
		ret = p_ptr(v);
	else
		ret = (int) write(1, l, 1);
	return (ret);
}

int	ft_printf(const char *l, ...)
{
	va_list	v;
	int		ret;

	va_start(v, l);
	ret = 0;
	if (l == NULL)
		return (0);
	while (*l)
	{
		if (*l == '%')
		{
			l++;
			ret += print_arg(l, v);
			l++;
		}
		else
		{
			ret += (int) write(1, l, 1);
			l++;
		}
	}
	va_end(v);
	return (ret);
}
