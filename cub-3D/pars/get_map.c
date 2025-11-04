/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 07:02:41 by marrandr          #+#    #+#             */
/*   Updated: 2025/10/24 16:31:42 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./parsing.h"

char	**lst_struct_to_lst_string(t_list **lst)
{
	int		i;
	char	**res;
	t_list	*temp;
	t_list	*swap;

	res = ft_calloc (ft_lstsize(*lst) + 1, sizeof(char *));
	if (!res)
	{
		perror("Malloc ");
		return (NULL);
	}
	temp = *lst;
	i = 0;
	while (temp)
	{
		res[i] = temp->content;
		swap = temp->next;
		free (temp);
		temp = swap;
		i++;
	}
	*lst = NULL;
	return (res);
}

int	ft_all_space(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	skip_and_check(char *line, int fd, t_list **lst, int *p)
{
	free (line);
	line = line_without_new_line(fd);
	while (line)
	{
		if (line[0] && !ft_all_space(line))
		{
			ft_lstclear(lst, free);
			free (line);
			put_error("map ", "empty line detected on map");
			*p = -1;
			return (0);
		}
		free (line);
		line = line_without_new_line(fd);
	}
	return (1);
}

char	**get_map(int fd)
{
	int		status_save;
	char	**res;
	t_list	*lst;
	char	*line;

	lst = NULL;
	res = NULL;
	status_save = 0;
	line = line_without_new_line(fd);
	while (line && status_save != -1)
	{
		if (line[0] && !ft_all_space(line))
			status_save = 1;
		if (!line[0] && status_save)
			skip_and_check(line, fd, &lst, &status_save);
		else if (line[0] && status_save)
			ft_lstadd_back(&lst, ft_lstnew(line));
		else
			free (line);
		line = line_without_new_line(fd);
	}
	if (status_save != -1)
		res = lst_struct_to_lst_string(&lst);
	return (res);
}
