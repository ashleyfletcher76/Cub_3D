/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:09:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/22 10:45:06 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

static int	draw_line(mlx_image_t *image, t_cube *cube)
{
	double	deltaX;
	double	deltaY;
	int		pixels;
	float	pixelX;
	float	pixelY;

	deltaX = cube->player.endX - cube->player.beginX;
	deltaY = cube->player.endY - cube->player.beginY;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	pixelX = cube->player.beginX;
	pixelY = cube->player.beginY;
	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels--)
	{
		if (pixelX >= 0 && pixelX < image->width && pixelY >= 0
			&& pixelY < image->height)
			mlx_put_pixel(image, pixelX, pixelY, cube->player.color);
		pixelX += deltaX;
		pixelY += deltaY;
	}
	return (true);
}

void draw_player(t_cube *cube)
{
	int	x;
	int	y;
	int	drawX;
	int	drawY;

	x = -5;
	while (++x < 5)
	{
		y = -5;
		while (++y < 5)
		{
			drawX = cube->player.px + x;
			drawY = cube->player.py + y;
			if (drawX >= 0 && drawX < WIDTH && drawY >= 0 && drawY < HEIGHT)
				mlx_put_pixel(cube->image, drawX, drawY, pixel(255, 255, 0, 255));
		}
	}
}

static void	init_line(t_cube *cube)
{
	cube->player.beginX = cube->player.px;
	cube->player.beginY = cube->player.py;
	cube->player.endX = cube->player.px + cube->player.pdx * 5;
	cube->player.endY = cube->player.py + cube->player.pdy * 5;
	cube->player.color = pixel(255, 255, 0, 255);
}

void	draw_pixel(t_cube *cube)
{
	draw_player(cube);
	init_line(cube);
	draw_line(cube->image, cube);
}
