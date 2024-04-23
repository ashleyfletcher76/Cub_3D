/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:09:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/23 15:17:13 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

/*static int	draw_line(mlx_image_t *image, t_cube *cube)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	float	pixel_x;
	float	pixel_y;

	delta_x = cube->line.end_x - cube->line.begin_x;
	delta_y = cube->line.end_y - cube->line.begin_y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	pixel_x = cube->line.begin_x;
	pixel_y = cube->line.begin_y;
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels--)
	{
		if (pixel_x >= 0 && pixel_x < image->width && pixel_y >= 0
			&& pixel_y < image->height)
			mlx_put_pixel(image, pixel_x, pixel_y, cube->player.color);
		pixel_x += delta_x;
		pixel_y += delta_y;
	}
	return (true);
}*/

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

void	draw_player(t_cube *cube)
{
	int	x;
	int	y;
	int	draw_x;
	int	draw_y;

	x = -5;
	while (++x < 5)
	{
		y = -5;
		while (++y < 5)
		{
			draw_x = cube->player.px + x;
			draw_y = cube->player.py + y;
			if (draw_x >= 0 && draw_x < WIDTH && draw_y >= 0 && draw_y < HEIGHT)
				mlx_put_pixel(cube->image, draw_x, draw_y,
					pixel(255, 255, 0, 255));
		}
	}
}

t_line	init_line(float beginx, float beginy, float endx, float endy)
{
	t_line line;

	line.begin_x = beginx;
	line.begin_y = beginy;
	line.end_x = endx;
	line.end_y = endy;
	return (line);
}

void	draw_pixel(t_cube *cube)
{
	t_line	line;

	line = init_line(cube->player.px, cube->player.py, cube->player.px + cube->player.pdx * 5, cube->player.py + cube->player.pdy * 5);
	draw_player(cube);
	draw_line(cube->image, line, pixel(255, 255, 0, 255));
}
