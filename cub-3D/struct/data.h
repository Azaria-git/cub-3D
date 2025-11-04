/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:33:56 by marrandr          #+#    #+#             */
/*   Updated: 2025/11/04 11:13:38 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# define TILE_SIZE 64
# define MINIMAP_TILS 8
# define FOV 60

typedef struct s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

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
	int			width;
	int			height;
	char		*south;
	char		*east;
	char		*west;
}				t_texture;

typedef struct s_minimap
{
	t_img		*img;
	char		*img_adrr;
	int			bpp;
	int			size_line;
	int			endian;
	void		*wall;
	void		*floor;
	int			screen_width;
	int			screen_height;
	void		*player;

}				t_minimap;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		*img;
	double		mid_height;
	double		fov;
	double		mi_fov;
	t_minimap	*mini_map;
	int			screen_width;
	int			screen_height;
	t_player	player;
	t_texture	texture;
	int			color_floor;
	int			color_ceiling;
	char		**map;
	int			map_width;
	int			map_height;
}				t_data;

#endif
