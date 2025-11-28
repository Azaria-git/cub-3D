/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrandr <marrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:27:56 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/27 11:45:26 by marrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSING_H
# define PARSING_H

# include "../Libft/libft.h"
# include "../struct/data.h"
# include "../common/common.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_count_word(char const *str, char *sep);
void	put_error(char *source, char *info);
void	ft_free_split(char **s);
char	*skip_first_word(char *line, char *w);
int		ft_is_f_loop(int (*f)(int), char *s);
int		check_type_file(char *path);
void	manager_a_line(char *s, t_data **data, int *check, char **split);
int		ft_atoi_strict(char *str);
char	**ft_strsplit(char *s, char *sep, int i, int j);
int		count_word_split(char **split);
int		check_type_file(char *path);
int		ft_space_and_digit(int s);
int		ft_lendigit(char *s);
char	**get_map(int fd);
t_data	*check_and_filling(char *path);
char	*line_without_new_line(int fd);
int		map_check(t_data *data);
int		error_map(char *error, char exept);
int		calculate_w_and_h(char **map, int *x, int *y);
int		len_line(char *line, int *p);
int		check_texture(t_data *data);
int		ft_isspace(char c);
char	**ft_split_exam(char const *s, char *sep);
int		ft_ischar(const char *str, char c);

#endif