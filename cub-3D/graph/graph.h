/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:31:47 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/04 12:23:43 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include "../minilibx-linux/mlx.h"
# include "../struct/data.h"
# include "../common/common.h"

# define STEP_SIZE 0.1
# define PLANE_SIZE 0.66

typedef struct s_tex
{
	double		step;
	int			text_x;
}			t_tex;

typedef struct s_ray
{
	double	ray_angle;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_dist;
	double	line_height;
	double	distance;
	int draw_start;
	int draw_end;
}			t_ray;
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		raycasting(t_data *data);
void	draw_rays(t_data *data, int col);
void	draw_terrain(t_data *data);
double text_x_calculation(t_data *data, t_ray *ray);
void draw_text(t_data *data, t_ray *ray, int colon);
#endif