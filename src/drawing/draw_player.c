/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:09:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/13 12:36:17 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	draw_player(t_cube *cube, double mx, double my)
{
	int	x;
	int	y;
	int	draw_x;
	int	draw_y;
	int	pixel_size;

	pixel_size = cube->map->pixel_scale;
	x = -pixel_size;
	while (++x < pixel_size)
	{
		y = -pixel_size;
		while (++y < pixel_size)
		{
			draw_x = x + mx;
			draw_y = y + my;
			if (draw_x >= 0 && draw_y < cube->map->mini_width
				&& draw_x >= 0 && draw_y < cube->map->mini_height)
				mlx_put_pixel(cube->image, draw_x, draw_y,
					pixel(0, 0, 255, 255));
		}
	}
}

void	draw_pixel(t_cube *cube)
{
	t_line	line;
	double	mx;
	double	my;

	mx = cube->player.px * cube->map->scale;
	my = cube->player.py * cube->map->scale;
	line = init_line(mx, my, mx + cube->player.pdx * cube->map->scale, my
			+ cube->player.pdy * cube->map->scale);
	draw_player(cube, mx, my);
	draw_line(cube->image, line, pixel(0, 0, 255, 255));
}
