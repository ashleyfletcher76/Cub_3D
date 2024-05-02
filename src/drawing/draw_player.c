/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:09:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/01 14:46:13 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

int	draw_line(mlx_image_t *image, t_line line, int color)
{
	double	deltax;
	double	deltay;
	int		pixels;
	double	pixelx;
	double	pixely;

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

t_line	init_line(double beginx, double beginy, double endx, double endy)
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
	int draw_x;
	int draw_y;

	x = -MAPSIZE / 8;
	while (++x < MAPSIZE / 8)
	{
		y = - MAPSIZE / 8;
		while (++y < MAPSIZE / 8)
		{
			draw_x = x + cube->player.px;
			draw_y = y + cube->player.py;
			if (draw_x >= 0 && draw_y < WIDTH && draw_x >= 0 && draw_y < HEIGHT)
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
