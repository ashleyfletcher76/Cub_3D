/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:55:02 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/05 16:55:35 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

void	init_textures(t_cube *cube)
{
	u_int8_t *pixels;
	int color;
	cube->wall_xpm = mlx_load_xpm42("/Users/muhakose/Desktop/projects/cub_3d/cub3d_github/images/blue.xpm42");
	cube->wall_tex = cube->wall_xpm->texture;


	uint32_t x,y;
	for (x = 0; x < cube->wall_tex.width; x++)
	{
		for (y = 0; y < cube->wall_tex.height; y++)
		{
			int index = (x * cube->wall_tex.width + y) * 4;
			pixels = &cube->wall_tex.pixels[index];
			color = pixel(pixels[0] , pixels[1] , pixels[2], pixels[3]);
			mlx_put_pixel(cube->image, x, y, color);
		}
	}
}
