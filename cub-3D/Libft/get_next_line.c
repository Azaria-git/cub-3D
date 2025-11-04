/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:03:27 by aravelom          #+#    #+#             */
/*   Updated: 2025/05/12 08:49:09 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **ptr1)
{
	if (ptr1 != NULL && *ptr1 != NULL)
	{
		free(*ptr1);
		*ptr1 = NULL;
		ptr1 = NULL;
	}
}

static char	*cut_line(char **rest)
{
	ssize_t	i;
	char	*line_tmp;

	i = 0;
	line_tmp = NULL;
	line_tmp = ft_strjoin_gnl(NULL, *rest);
	free_all(rest);
	if (line_tmp == NULL)
		return (NULL);
	while (line_tmp[i] != '\n' && line_tmp[i] != 0)
		i++;
	if (line_tmp[i] == 0)
	{
		free_all(rest);
		return (line_tmp);
	}
	*rest = ft_strjoin_gnl(NULL, line_tmp + i + 1);
	if ((*rest)[0] == '\0')
		free_all(rest);
	line_tmp[i + 1] = 0;
	return (line_tmp);
}

char	*get_next_line(int fd)
{
	static char		*rest = NULL;
	char			*buff;
	static ssize_t	r = 1;

	if (fd < 0 || BUFFER_SIZE <= 0 || r <= 0)
		return (NULL);
	while (!ft_strchr_gnl(rest, '\n'))
	{
		buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == NULL)
			return (NULL);
		r = read(fd, buff, BUFFER_SIZE);
		if (r <= 0)
		{
			free_all(&buff);
			return (rest);
		}
		buff[r] = 0;
		rest = ft_strjoin_gnl(rest, buff);
		free_all(&buff);
	}
	return (cut_line(&rest));
}
