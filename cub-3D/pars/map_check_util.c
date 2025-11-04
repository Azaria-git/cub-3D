/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 07:48:32 by aravelom          #+#    #+#             */
/*   Updated: 2025/10/24 16:32:29 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./parsing.h"

int	error_map(char *error, char exept)
{
	write(2, "Error\n", 6);
	write(2, "Invalid map: ", 13);
	if (error && error[0])
		write(2, error, ft_strlen(error));
	if (exept)
	{
		write(2, " ", 1);
		write(2, "`", 1);
		write(2, &exept, 1);
		write(2, "'", 1);
	}
	write(2, "\n", 1);
	return (1);
}

int	width(char *str, int *x)
{
	int	w;
	int	s;

	w = 0;
	s = 0;
	while (str[w])
	{
		if (str[w] == ' ')
			s++;
		w++;
	}
	if (s == w)
	{
		error_map("there is a line composed only of spaces", 0);
		return (1);
	}
	if (w > *x)
		*x = w;
	return (0);
}

int	calculate_w_and_h(char **map, int *x, int *y)
{
	if (!map || !map[0])
		return (error_map("Empty map", 0));
	*x = 0;
	*y = 0;
	while (map[*y])
	{
		if (map[*y][0] == '\0')
			return (error_map("empty line inside the map", 0));
		if (width(map[*y], x))
			return (1);
		*y = (*y) + 1;
	}
	if (*x <= 3 || *y <= 3)
		return (error_map("height and/or width too short", 0));
	return (0);
}

int	len_line(char *line, int *p)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] != '0' && line[x] != '1' && line[x] != 'N' && line[x] != 'S'
			&& line[x] != 'E' && line[x] != 'W' && line[x] != ' ')
			return (error_map("Invalid character in map", line[x]) * -1);
		if (line[x] == 'N' || line[x] == 'S' || line[x] == 'E'
			|| line[x] == 'W')
			*p = *p + 1;
		x++;
	}
	return (x);
}
