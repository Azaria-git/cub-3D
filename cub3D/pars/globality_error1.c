/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globality_error1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 09:07:21 by marrandr          #+#    #+#             */
/*   Updated: 2025/11/04 10:50:36 by marrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing.h"

void	ft_init_data(t_data **data)
{
	(*data)->mlx = NULL;
	(*data)->win = NULL;
	(*data)->map = NULL;
	(*data)->texture.east = NULL;
	(*data)->texture.north = NULL;
	(*data)->texture.west = NULL;
	(*data)->texture.south = NULL;
}

char	*line_without_new_line(int fd)
{
	char	*s;
	int		i;

	s = NULL;
	s = get_next_line(fd);
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (i > 0 && s[i - 1] == '\n')
		s[i - 1] = 0;
	return (s);
}

void	filling_data(int fd, t_data **data, int *p_check)
{
	char	*s;
	int		word;
	int		check[6];

	s = line_without_new_line(fd);
	ft_memset(check, 0, 24);
	while (*data && s && *p_check < 6)
	{
		word = ft_count_word(s, ' ');
		if (word > 1 && *p_check < 6)
		{
			(*p_check)++;
			manager_a_line(s, data, check, NULL);
		}
		else if (s[0] && word < 2)
		{
			(*p_check) = 1;
			put_error("line on file", "missing info or invalid line detected");
			ft_free_data(data);
		}
		ft_free_null ((void **)&s);
		if (*p_check < 6)
			s = line_without_new_line(fd);
	}
	ft_free_null ((void **)&s);
}

void	manage_save_data(t_data **data, int fd)
{
	int	check;

	check = 0;
	ft_init_data(data);
	filling_data(fd, data, &check);
	if (check < 6)
	{
		if (check == 0)
			put_error("file ", "no info in file");
		ft_free_data(data);
	}
	if (!check_texture(*data))
		ft_free_data(data);
	if (check == 6 && *data)
		(*data)->map = get_map(fd);
	if (*data && !(*data)->map)
		ft_free_data(data);
	if (*data && map_check(*data))
		ft_free_data(data);
}

t_data	*check_and_filling(char *path)
{
	t_data	*result;
	int		fd;

	result = NULL;
	if (!check_type_file(path))
		return (NULL);
	fd = open (path, O_RDONLY);
	if (fd == -1)
	{
		put_error("file", "no read permission or file does not exist");
		return (NULL);
	}
	result = malloc (sizeof(t_data));
	if (!result)
	{
		perror ("Malloc: ");
		close (fd);
		return (NULL);
	}
	manage_save_data(&result, fd);
	close (fd);
	return (result);
}
