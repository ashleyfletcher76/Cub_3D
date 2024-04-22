/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:09:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/22 09:43:22 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

void	draw_grid_basic(t_cube *cube)
{
	int	x;
	int	y;
	int	grid_size;

	x = 40;
	grid_size = 50;
	while (x <= cube->max_width)
	{
		y = 40;
		while (y <= cube->max_height)
		{
			mlx_put_pixel(cube->image, x, y, pixel(255, 255, 255, 255));
			y++;
		}
		x += grid_size;
	}
	y = 40;
	while (y <= cube->max_height)
	{
		x = 40;
		while (x <= cube->max_width)
		{
			mlx_put_pixel(cube->image, x, y, pixel(255, 255, 255, 255));
			x++;
		}
		y += grid_size;
	}
}

int	draw_line(mlx_image_t *image, float beginX, float beginY, float endX, float endY, float color)
{
	double	deltaX = endX - beginX;
	double	deltaY = endY - beginY;

	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	float	pixelX = beginX;
	float	pixelY = beginY;

	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels)
	{
		mlx_put_pixel(image, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return (true);
}

void	draw_player(t_cube *cube)
{
	int	x;
	int	y;

	x = -5;
	while (++x < 5)
	{
		y = -5;
		while (++y < 5)
			mlx_put_pixel(cube->image, cube->player.px + x, cube->player.py + y,
				pixel(255, 255, 0, 255));
	}
}


void	draw_pixel(t_cube *cube)
{
	draw_player(cube);
	draw_line(cube->image, cube->player.px, cube->player.py, cube->player.px + cube->player.pdx * 5, cube->player.py + cube->player.pdy * 5 , pixel(255, 255, 0, 255));

}
