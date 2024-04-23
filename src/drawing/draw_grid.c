/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:09:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/22 13:25:35 by muhakose         ###   ########.fr       */
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

// draw_line function takes a float array of size 4
// first 2 value are the x and y coordinates that line starting form
// line[0] = beginX
// line[1] = beginY
// last 2 values are the x0 and y0 that are the
// cordinates for the ending coordintes for the line.
// line[2] = endX
// line[3] = endY

int	draw_line(mlx_image_t *image, float line[4], float color)
{
	double	deltax;
	double	deltay;
	int		pixels;
	float	pixelx;
	float	pixely;

	deltay = line[3] - line[1];
	deltax = line[2] - line[0];
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	pixelx = line[0];
	pixely = line[1];
	deltax /= pixels;
	deltay /= pixels;
	while (pixels)
	{
		mlx_put_pixel(image, pixelx, pixely, color);
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
	return (true);
}

void	draw_player(t_cube *cube)
{
	int		x;
	int		y;
	float	line[4];

	x = -5;
	while (++x < 5)
	{
		y = -5;
		while (++y < 5)
			mlx_put_pixel(cube->image, cube->player.px + x, cube->player.py + y,
				pixel(255, 255, 0, 255));
	}
	line[0] = cube->player.px;
	line[1] = cube->player.py;
	line[2] = cube->player.px + cube->player.pdx * 5;
	line[3] = cube->player.py + cube->player.pdy * 5;
	draw_line(cube->image, line, pixel(255, 255, 0, 255));
}

void	draw_pixel(t_cube *cube)
{
	draw_player(cube);
}

	//draw_rays(cube);
