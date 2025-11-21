/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trapeze_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aravelom <aravelom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:19:26 by aravelom          #+#    #+#             */
/*   Updated: 2025/11/21 11:18:55 by aravelom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void draw_sprite(t_img *dst, t_img *src, int x, int y)
{
    int i, j;
    int color;

    for (j = 0; j < src->height; j++)
    {
        for (i = 0; i < src->width; i++)
        {
            color = get_pixel_color(src, i, j);
            my_mlx_pixel_put(dst, x + i, y + j, color);
        }
    }
}

void draw_trapeze_map(t_data *data)
{
    t_coord pxl;
    int line_width;
    int top_width = data->map_width * MINIMAP_TILS * 0.7;
    int x_offset;

    float u;       // coordonnée horizontale normalisée
    int src_x;
    int src_y;

    // --- DESSIN DU TRAPÈZE ---
    pxl.y = 0;
    while (pxl.y < data->map_screen_height)
    {
        // largeur projetée de la ligne y
        line_width = top_width +
            ((data->map_screen_width - top_width) *
             pxl.y) / data->map_screen_height;

        // centrer le trapèze
        x_offset = (data->map_screen_width - line_width) / 2;

        pxl.x = 0;
        while (pxl.x < line_width)
        {
            // coordonnée horizontale dans la texture rectangle
            u = (float)pxl.x / (float)line_width;
            src_x = u * (data->map_width * MINIMAP_TILS);

            // coordonnée verticale dans la texture
            float v = (float)pxl.y / (float)data->map_screen_height;
            src_y = v * (data->map_height * MINIMAP_TILS);

            // sécurité
            if (src_x >= 0 && src_x < data->map_width * MINIMAP_TILS &&
                src_y >= 0 && src_y < data->map_height * MINIMAP_TILS)
            {
                int color = get_pixel_color(data->map_img, src_x, src_y);

                // position finale
                my_mlx_pixel_put(data->img,
                    data->trap_start.x + x_offset + pxl.x,
                    data->trap_start.y + pxl.y,
                    color);
            }

            pxl.x++;
        }
        pxl.y++;
    }


    // --- DESSIN DE LA POSITION DU JOUEUR ---
    // Convertir position du joueur dans la texture rectangle
    float tex_player_x = data->player.pos_x * MINIMAP_TILS;
    float tex_player_y = data->player.pos_y * MINIMAP_TILS;

    // 1) convertir y → trapèze
    int trap_y = (tex_player_y / (data->map_height * MINIMAP_TILS))
                 * data->map_screen_height;

    // 2) largeur du trapèze à ce y
    int p_line_width = top_width +
        ((data->map_screen_width - top_width) *
        trap_y) / data->map_screen_height;

    // 3) offset
    int p_x_offset = (data->map_screen_width - p_line_width) / 2;

    // 4) coordonnée horizontale normalisée du joueur
    float p_u = tex_player_x / (float)(data->map_width * MINIMAP_TILS);

    // 5) conversion en x dans le trapèze
    int trap_x = p_u * p_line_width + p_x_offset;

    // --- DESSIN DU SPRITE DU JOUEUR AU CENTRE ---
    draw_sprite(
        data->img,
        &data->texture.location_icon,
        data->trap_start.x + trap_x - data->texture.location_icon.width / 2,
        data->trap_start.y + trap_y - data->texture.location_icon.height / 2
    );
}


// void draw_trapeze_map(t_data *data)
// {
//     t_coord pxl;
//     int line_width;
//     int top_width = data->map_width * MINIMAP_TILS * 0.5;
//     int x_offset;

//     int src_x, src_y;
//     float u; // coordonnée normalisée [0..1]

//     pxl.y = 0;
//     while (pxl.y < data->map_screen_height)
//     {
//         // largeur de la ligne du trapèze
//         line_width = top_width +
//             ((data->map_screen_width - top_width) * pxl.y) / data->map_screen_height;

//         // centrer
//         x_offset = (data->map_screen_width - line_width) / 2;

//         pxl.x = 0;
//         while (pxl.x < line_width)
//         {
//             // conversion en coordonnée normalisée (0 → 1)
//             u = (float)pxl.x / (float)line_width;

//             // coordonnées sources dans la texture rectangle
//             src_x = u * (data->map_width * MINIMAP_TILS);
//             src_y = (float)pxl.y / (float)data->map_screen_height
//                     * (data->map_height * MINIMAP_TILS);

//             // sécurité
//             if (src_x >= 0 && src_x < data->map_width * MINIMAP_TILS &&
//                 src_y >= 0 && src_y < data->map_height * MINIMAP_TILS)
//             {
//                 int color = get_pixel_color(data->map_img, src_x, src_y);

//                 // position finale dans l'image
//                 my_mlx_pixel_put(data->img,
//                     pxl.x + x_offset + data->trap_start.x,
//                     pxl.y + data->trap_start.y,
//                     color
//                 );
//             }
//             pxl.x++;
//         }
//         pxl.y++;
//     }
// }


// void	draw_trapeze_map(t_data *data)
// {
// 	t_coord	map;
// 	int		x_trap;
// 	int		top_width;
// 	int		x_offset;
// 	int		line_width;

// 	top_width = data->map_width * MINIMAP_TILS * 0.7;
// 	map.y = 0;
// 	while (map.y < data->map_screen_height)
// 	{
// 		line_width = top_width + ((data->map_screen_width - top_width) * map.y)
// 			/ data->map_screen_height;
// 		x_offset = (data->map_screen_width - line_width) / 2;
// 		map.x = 0;
// 		while (map.x < data->map_width * MINIMAP_TILS)
// 		{
// 			x_trap = map.x * line_width / (data->map_width * MINIMAP_TILS)
// 				+ x_offset;
// 			if (data->map[map.y / MINIMAP_TILS][map.x / MINIMAP_TILS] == '1')
// 				my_mlx_pixel_put(data->img, x_trap + data->trap_start.x, map.y
// 					+ data->trap_start.y, 0x444444);
// 			else if (data->player.map_y == map.y / MINIMAP_TILS
// 				&& data->player.map_x == map.x / MINIMAP_TILS)
// 				my_mlx_pixel_put(data->img, x_trap + data->trap_start.x, map.y
// 					+ data->trap_start.y, 0xFF0000);
// 			else if (data->map[map.y / MINIMAP_TILS][map.x
// 				/ MINIMAP_TILS] != 'X')
// 				my_mlx_pixel_put(data->img, x_trap + data->trap_start.x, map.y
// 					+ data->trap_start.y, 0x888888);
// 			map.x++;
// 		}
// 		map.y++;
// 	}
// }

// void draw_minimap_rotate(t_data *data)
// {
//     float c_x, c_y, r_x, r_y;
//     t_coord pxl;
//     int src_x, src_y;
//     int color;
//     int radius = MINIMAP_SIZE / 2;
// 	float decal = 1.570796;
	
//     pxl.y = 0;
//     while (pxl.y < MINIMAP_SIZE)
//     {
//         pxl.x = 0;
//         while (pxl.x < MINIMAP_SIZE)
//         {
//             c_x = pxl.x - radius;
//             c_y = pxl.y - radius;
//             if (c_x * c_x + c_y * c_y > radius * radius)
//             {
//                 pxl.x++;
//                 continue;
//             }
//             r_x = c_x * cos(data->player.orientation + decal) - c_y * sin(data->player.orientation + decal);
//             r_y = c_x * sin(data->player.orientation + decal) + c_y * cos(data->player.orientation + decal);
//             src_x = (int)(data->player.pos_x * MINIMAP_TILS + r_x);
//             src_y = (int)(data->player.pos_y * MINIMAP_TILS + r_y);
//             if (src_x >= 0 && src_x < data->map_width * MINIMAP_TILS &&
//                 src_y >= 0 && src_y < data->map_height * MINIMAP_TILS)
//             {
//                 color = get_pixel_color(data->map_img, src_x, src_y);
//             }
//             else
//                 color = 0x0000ff;
//             my_mlx_pixel_put(data->img, pxl.x, pxl.y, color);
//             pxl.x++;
//         }
//         pxl.y++;
//     }
// }