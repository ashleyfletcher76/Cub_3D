/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:09:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/29 11:16:44 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

int	draw_line(mlx_image_t *image, t_line line, float color)
{
	float	deltax;
	float	deltay;
	int		pixels;
	float	pixelx;
	float	pixely;

	deltay = line.end_y - line.begin_y;
	deltax = line.end_x - line.begin_x;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	pixelx = line.begin_x;
	pixely = line.begin_y;
	deltax /= pixels;
	deltay /= pixels;
	while (pixels)
	{
		if (pixelx >= 0 && pixelx < image->width && pixely >= 0
			&& pixely < image->height)
			mlx_put_pixel(image, pixelx, pixely, color);
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
	return (true);
}

t_line	init_line(float beginx, float beginy, float endx, float endy)
{
	t_line	line;

	line.begin_x = beginx;
	line.begin_y = beginy;
	line.end_x = endx;
	line.end_y = endy;
	return (line);
}

void	draw_player(t_cube *cube)
{
	int	x;
	int	y;
	int	draw_x;
	int	draw_y;

	x = -MAPSIZE / 8;
	while (++x < MAPSIZE / 8)
	{
		y = -MAPSIZE / 8;
		while (++y < MAPSIZE / 8)
		{
			draw_x = cube->player.px + x;
			draw_y = cube->player.py + y;
			if (draw_x >= 0 && draw_x < WIDTH && draw_y >= 0 && draw_y < HEIGHT)
				mlx_put_pixel(cube->image, draw_x, draw_y,
					pixel(255, 255, 0, 255));
		}
	}
}

void	draw_pixel(t_cube *cube)
{
	t_line	line;

	line = init_line(cube->player.px, cube->player.py, cube->player.px
			+ cube->player.pdx * MAPSIZE / 4, cube->player.py
			+ cube->player.pdy * MAPSIZE / 4);
	draw_player(cube);
	draw_line(cube->image, line, pixel(255, 255, 0, 255));
}
