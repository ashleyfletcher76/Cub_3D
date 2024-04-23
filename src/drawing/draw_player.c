/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:09:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/23 09:49:37 by asfletch         ###   ########.fr       */
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
