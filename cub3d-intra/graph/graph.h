/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:31:47 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/28 17:15:38 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include "../common/common.h"
# include "../minilibx-linux/mlx.h"
# include "../struct/data.h"

# define STEP_SIZE 0.1
# define PLANE_SIZE 0.66
# define RADIUS 76

typedef struct s_d_coorde
{
	double x;
	double y;
}			t_d_coorde;

typedef struct s_tex
{
	double	step;
	int		text_x;
}			t_tex;


typedef struct s_ray
{
	t_coord		pixel;

	float		angle;
	
	float		ray_dir_x;
    float		ray_dir_y;
	
	double		delta_dist_x;
	double		delta_dist_y;

	t_d_coorde		step;

	float		side_dist_x;
	float		side_dist_y;

	t_coord		map_pxl;

	int			side_v;
	int			is_door;

	float 		perp_dist;

	float		line_height;

	// t_coord		v;
	// t_coord		h;
	
	t_d_coorde		v;
	t_d_coorde		h;
	
	t_coord		pxl_dest;

	int			draw_start;
	int			draw_end;

}				t_ray;

void map_img(t_data *data, t_img *map_img);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		raycasting(t_data *data);
int			get_pixel_color(t_img *img, int pxl_x, int pxl_y);
void		draw_minimap_rotate(t_data *data);
void		draw_trapeze_map(t_data *d);
void		texturing(t_data *data, t_ray *ray, int colon);
void map_img_dbg(t_data *data, t_img *map_img);

#endif