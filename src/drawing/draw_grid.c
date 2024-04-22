/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:09:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/22 11:44:42 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

static int	draw_line(mlx_image_t *image, t_cube *cube)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	float	pixel_x;
	float	pixel_y;

	delta_x = cube->line.end_x - cube->line.beginX;
	delta_x = cube->line.end_y - cube->line.begin_y;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	pixel_x = cube->line.beginX;
	pixel_y = cube->line.beginY;
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels--)
	{
		if (pixelX >= 0 && pixelX < image->width && pixelY >= 0
			&& pixelY < image->height)
			mlx_put_pixel(image, pixelX, pixelY, cube->player.color);
		pixel_x += delta_x;
		pixel_y += delta_y;
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
			if (drawX >= 0 && draw_x < WIDTH && draw_y >= 0 && drawY < HEIGHT)
				mlx_put_pixel(cube->image, draw_x, draw_y,
					pixel(255, 255, 0, 255));
		}
	}
}

static void	init_line(t_cube *cube)
{
	cube->line.begin_x = cube->player.px;
	cube->line.begin_y = cube->player.py;
	cube->line.end_x = cube->player.px + cube->player.pdx * 5;
	cube->line.end_y = cube->player.py + cube->player.pdy * 5;
	cube->player.color = pixel(255, 255, 0, 255);
}

void	draw_pixel(t_cube *cube)
{
	draw_player(cube);
	init_line(cube);
	draw_line(cube->image, cube);
}
