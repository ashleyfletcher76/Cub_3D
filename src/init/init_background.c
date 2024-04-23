/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:10:35 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/22 10:49:31 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

static void	non_grid_lines(t_cube *cube, uint32_t x, uint32_t y, int i)
{
	if (cube->map->map[y / i][x / i] == '1')
		mlx_put_pixel(cube->image, x, y, pixel(255, 255, 255, 255));
	else if (cube->map->map[y / i][x / i] == '0' )
		mlx_put_pixel(cube->image, x, y, pixel(0, 0, 0, 255));
	else if (cube->map->map[y / i][x / i] == ' ')
		mlx_put_pixel(cube->image, x, y, pixel(128, 128, 128, 255));
	else
		mlx_put_pixel(cube->image, x, y, pixel(0, 0, 0, 0));
}

void background(void *param)
{
	uint32_t	y;
	uint32_t	x;
	int			i;
	t_cube		*cube;

	cube = (t_cube *)param;
	i = cube->map_size;
	x = -1;
	while (++x < cube->image->width)
	{
		y = -1;
		while (++y < cube->image->height)
		{
			if (x % i == 0 || y % i == 0)
				mlx_put_pixel(cube->image, x, y, pixel(0, 0, 0, 0));
			else
				non_grid_lines(cube, x, y, i);
		}
	}
}
