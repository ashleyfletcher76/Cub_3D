/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:55:02 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/05 11:20:02 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

// void	init_textures(t_cube *cube)
// {

// 	u_int8_t *pixels;
// 	int color;
// 	cube->wall_xpm = mlx_load_xpm42("/Users/muhakose/Desktop/projects/cub_3d/cub3d_github/images/box.xpm42");
// 	cube->wall_tex = cube->wall_xpm->texture;
// 	//mlx_image_t* img = mlx_texture_to_image(cube->mlx, &cube->wall_xpm->texture);
// 	//mlx_image_to_window(cube->mlx, img, 0, 0);

// 	uint32_t x,y;
// 	for (y = 0; y < cube->wall_tex.height; y++)
// 	{
// 		for (x = 0; x < cube->wall_tex.width; x++)
// 		{
// 			int index = (x * cube->wall_tex.height + y);
// 			pixels = &cube->wall_tex.pixels[index * 4];
// 			color = pixel(pixels[0] , pixels[1] , pixels[2], pixels[3]);
// 			mlx_put_pixel(cube->image, x, y, color);
// 		}
// 	}
// }
