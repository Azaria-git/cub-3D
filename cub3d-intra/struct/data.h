/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:33:56 by marrandr          #+#    #+#             */
/*   Updated: 2025/11/28 07:11:05 by aravelom         ###   ########.fr       */
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
	t_coord		pxl_pos;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		orientation;
}				t_player;

typedef struct s_texture
{
	char		*south;
	char		*east;
	char		*west;
	char		*north;
	
	t_img		img_no;
	t_img		img_we;
	t_img		img_so;
	t_img		img_ea;
	
	t_img		*current;

	t_img		door_no;
	t_img		door_we;
	t_img		door_so;
	t_img		door_ea;
	
	t_img       space_tex;
	t_img       wall_tex;
	t_img		floor_tex;
	t_img		location_icon;
	t_img		triangle_icon;

}				t_texture;

typedef struct s_dbg
{
	void *win;
	t_img img;
} t_dbg;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		*img;
	int			open_door;
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
	int		trap_x_offset;
	int		trap_top_width;
	int   show_trapeze;
	//
	t_dbg	dbg;
}				t_data;



#endif
