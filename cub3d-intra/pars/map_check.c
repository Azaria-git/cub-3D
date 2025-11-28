/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:29:14 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/28 14:53:58 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./parsing.h"

static char	*check_line(char *line, int x, int width, int *p)
{
	int		len;
	char	*new;

	new = NULL;
	len = len_line(line, p);
	if (len < 0)
		return (NULL);
	else if (len == width)
		return (line);
	new = (char *)ft_calloc(width + 1, 1);
	if (!new)
	{
		print_error("malloc", "cannot allocate memory");
		return (NULL);
	}
	ft_strcpy(new, line);
	while (x < width)
	{
		new[x] = 'X';
		x++;
	}
	return (new);
}

static int	padding(char **map, int width)
{
	char	*line;
	int		y;
	int		x;
	int		p;

	y = -1;
	line = NULL;
	p = 0;
	while (map[++y])
	{
		x = ft_strlen(map[y]);
		line = check_line(map[y], x, width, &p);
		if (!line)
			return (1);
		if ((int)ft_strlen(line) != x)
		{
			free(map[y]);
			map[y] = line;
		}
	}
	if (p == 0)
		return (error_map("No player start position", 0));
	else if (p > 1)
		return (error_map("Multiple player start positions", 0));
	return (0);
}

static void	flood(char **map, int y, int x, int *error)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x] || map[y][x] == '1'
		|| map[y][x] == 'X' || *error)
		return ;
	if (map[y][x] == ' ')
		map[y][x] = 'X';
	else
	{
		*error = 1;
		return ;
	}
	flood(map, y + 1, x, error);
	flood(map, y - 1, x, error);
	flood(map, y, x + 1, error);
	flood(map, y, x - 1, error);
}

static int	border_check(char **map, int x, int y, t_data *data)
{
	int	error;

	error = 0;
	if (ft_strchr("NSEW0", map[y][x]) && (y == 0 || x == 0 || !map[y + 1]
			|| ft_strchr("X \0", map[y][x + 1]) || ft_strchr("X \0", map[y
				+ 1][x + 1]) || ft_strchr("X \0", map[y - 1][x - 1])
			|| ft_strchr("X \0", map[y + 1][x - 1]) || ft_strchr("X \0", map[y
				- 1][x + 1])))
		return (error_map("map not closed", 0));
	if (map[y][x] == ' ')
		flood(map, y, x, &error);
	if (error)
		return (error_map("map not closed", 0));
	if (ft_strchr("NSEW", map[y][x]))
	{
		if (map[y][x] == 'S')
			data->player.orientation = deg_to_rad(90);
		else if (map[y][x] == 'E')
			data->player.orientation = deg_to_rad(360);
		else if (map[y][x] == 'N')
			data->player.orientation = deg_to_rad(270);
		else
			data->player.orientation = deg_to_rad(180.5);
		data->player.pxl_pos.x = (x * TILE_SIZE) + TILE_SIZE / 2;
		data->player.pxl_pos.y = (y * TILE_SIZE) + TILE_SIZE / 2;
	}
	return (0);
}

int	map_check(t_data *data)
{
	char **map;
	int	y;
	int	x;

	map = NULL;
	if (data && data->map)
		map = data->map;
	if (calculate_w_and_h(map, &x, &y) || padding(map, x))
		return (1);
	data->map_height = y;
	data->map_width = x;
	data->map_screen_width = x * MINIMAP_TILS;
	data->map_screen_height = y * MINIMAP_TILS;
	data->mid_height = SCREEN_HEIGHT / 2;
	data->fov = deg_to_rad(FOV);
	data->mi_fov = data->fov / 2;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (border_check(map, x, y, data))
				return (1);
	}
	data->map = map;
	return (0);
}
