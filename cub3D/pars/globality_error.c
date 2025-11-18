/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globality_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:24:00 by marrandr          #+#    #+#             */
/*   Updated: 2025/10/29 17:38:33 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./parsing.h"

int	check_data_color(char **s)
{
	int	size_split;

	size_split = count_word_split(s);
	if (size_split == 5 && ft_strncmp(s[0], ",", 2) && !ft_strncmp(s[1], ",", 2)
		&& ft_strncmp(s[2], ",", 2) && !ft_strncmp(s[3], ",", 2)
		&& ft_strncmp(s[4], ",", 2))
		return (1);
	put_error("color", "format is R,G,B [0,255]");
	return (0);
}

void	check_and_add_color(char *info, char **split, t_data **data)
{
	int	i;
	int	rgb[5];

	i = 0;
	if (!check_data_color(split))
		return (ft_free_data(data));
	ft_bzero(rgb, 20);
	while (split[i])
	{
		rgb[i] = ft_atoi_strict(split[i]);
		if ((!(i % 2)) && (!ft_is_f_loop(ft_space_and_digit, split[i])
				|| ft_lendigit(split[i]) > 3 || (rgb[i] > 255 || rgb[i] < 0)))
		{
			ft_free_data(data);
			return (put_error("color argmument", "must be between 0 and 255"));
		}
		i++;
	}
	if (!ft_strncmp(info, "C", 2))
		(*data)->color_ceiling = (rgb[0] << 16 | rgb[2] << 8 | rgb[4] << 2);
	else if (!ft_strncmp(info, "F", 2))
		(*data)->color_floor = (rgb[0] << 16 | rgb[2] << 8 | rgb[4] << 2);
}

void	save_color_struct(char *info, char *line, t_data **data)
{
	char	**split;

	line = skip_first_word(line, info);
	if (!line)
	{
		put_error("color", "format invalid");
		ft_free_data(data);
	}
	if (ft_count_word(line, ',') != 3)
	{
		ft_free_data(data);
		return (put_error("color", "must be 3 numbers separated by commas"));
	}
	split = ft_strsplit(line, ',', 0);
	if (!split)
	{
		perror("Malloc: ");
		ft_free_data(data);
	}
	check_and_add_color(info, split, data);
	ft_free_split(split);
}

int	check_a_line(char *s, int *check, char **split, t_data **data)
{
	int	count;

	count = ft_count_word(s, ' ');
	split = ft_split(s, ' ');
	if (!split)
	{
		perror("Malloc: ");
		ft_free_data(data);
	}
	else if (count == 2 && !ft_strncmp(split[0], "NO", 3) && !check[0])
		check[0] = 1;
	else if (count == 2 &&!ft_strncmp(split[0], "SO", 3) && !check[1])
		check[1] = 1;
	else if (count == 2 && !ft_strncmp(split[0], "WE", 3) && !check[2])
		check[2] = 1;
	else if (count == 2 && !ft_strncmp(split[0], "EA", 3) && !check[3])
		check[3] = 1;
	else if (count >= 2 && !ft_strncmp(split[0], "F", 2) && !check[4])
		check[4] = 1;
	else if (count >= 2 && !ft_strncmp(split[0], "C", 2) && !check[5])
		check[5] = 1;
	else
		return (ft_free_split(split), 0);
	ft_free_split(split);
	return (1);
}

void	manager_a_line(char *s, t_data **data, int *check, char **split)
{
	if (check_a_line(s, check, NULL, data) == 0)
	{
		put_error(" line on file", "no valide line detected");
		return (ft_free_data(data));
	}
	split = ft_split(s, ' ');
	if (!split)
	{
		free (s);
		perror("Malloc: ");
		ft_free_data(data);
	}
	else if (!ft_strncmp(split[0], "NO", 3))
		(*data)->texture.north = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "SO", 3))
		(*data)->texture.south = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "WE", 3))
		(*data)->texture.west = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "EA", 3))
		(*data)->texture.east = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "F", 2) || !ft_strncmp(split[0], "C", 2))
		save_color_struct(split[0], s, data);
	ft_free_split(split);
}
