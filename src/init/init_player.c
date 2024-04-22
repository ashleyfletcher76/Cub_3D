/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:50:28 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/22 09:02:08 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

int32_t	pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	find_pos(t_cube *cube, char c)
{
	if (c == 'N')
	{
		cube->player.d = 'N';
		return (true);
	}
	else if (c == 'S')
	{
		cube->player.d = 'S';
		return (true);
	}
	else if (c == 'E')
	{
		cube->player.d = 'E';
		return (true);
	}
	else if (c == 'W')
	{
		cube->player.d = 'W';
		return (true);
	}
	return (false);
}


void	find_pl_pos(t_cube *cube)
{
	int i = 0;
	int j = 0;
	char **map = cube->map->map;

	while (i < cube->max_height)
	{
		j = 0;
		while(j < cube->max_width)
		{
			if (find_pos(cube, map[i][j]))
			{
				cube->player.px = j * cube->map_size;
				cube->player.py = i * cube->map_size;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_player(t_cube *cube)
{
	find_pl_pos(cube);
	cube->player.pdx = cos(cube->player.pa) * 5;
	cube->player.pdy = sin(cube->player.pa) * 5;
}

void	draw_line(t_cube *cube)
{
	printf("%f\n", cube->player.pdx);
	printf("%f\n", cube->player.pdy);
	int dx = fabs(cube->player.pdx * 5);
	int dy = fabs(cube->player.pdy * 5);
	int sx, sy;
	int x0 = cube->player.px;
	int y0 = cube->player.py;
	int x1 = cube->player.px + cube->player.pdx * 5;
	int y1 = cube->player.py + cube->player.pdy * 5;


	if (x0 < x1) sx = 1; else sx = -1;
	if (y0 < y1) sy = 1; else sy = -1;

	int err = dx - dy;
	int e2;

	while (1)
	{
		mlx_put_pixel(cube->image, x0, y0, pixel(255, 255, 0, 255));
		if (x0 == x1 && y0 == y1) break;

		e2 = 2 * err;
		if (e2 > -dy) { err -= dy; x0 += sx;}
		if (e2 < dx) { err += dx; y0 += sy;}
	}
}



void	draw_pixel(t_cube *cube)
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

	x = -2;
	while (++x < 2)
	{
		y = -2;
		while (++y < 2)
			mlx_put_pixel(cube->image, cube->player.px + cube->player.pdx * 5 + x, cube->player.py + cube->player.pdy * 5 + y,
				pixel(255, 255, 0, 255));
	}

	//draw_line(cube);
}
