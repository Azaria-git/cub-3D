/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:33:56 by marrandr          #+#    #+#             */
/*   Updated: 2025/11/21 11:42:10 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# define TILE_SIZE 64
# define MINIMAP_TILS 16
# define FOV 60
# define MINIMAP_SIZE 153
# define SCREEN_WIDTH 1366
# define SCREEN_HEIGHT 768

typedef struct s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_player
{
	int			map_x;
	int			map_y;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		orientation;
}				t_player;

typedef struct s_texture
{
	char		*north;
	t_img		*current;
	t_img		img_no;
	t_img		img_we;
	t_img		img_so;
	t_img		img_ea;
	t_img       space_tex;
	t_img       wall_tex;
	t_img		floor_tex;
	t_img		location_icon;
	t_img		triangle_icon;
	int			width;
	int			height;
	char		*south;
	char		*east;
	char		*west;
}				t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		*img;
	double		mid_height;
	double		fov;
	double		mi_fov;
	t_player	player;
	t_img		player_in_minimap;
	t_texture	texture;
	int			color_floor;
	int			color_ceiling;
	char		**map;
	t_img		*map_img;
	int			map_width;
	int			map_height;
	int			map_screen_width;
	int			map_screen_height;
	// 	map trapeze
	t_coord trap_start;
	int   show_trapeze;
}				t_data;

#endif
