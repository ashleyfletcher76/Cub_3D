/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_d_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:35:36 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/08 15:15:38 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	map_condition(t_cube *cube, uint32_t x, uint32_t y, double scale)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / scale);
	map_y = (int)(y / scale);
	return (cube->map->map[map_y][map_x]);
}

static void	non_grid_lines(t_cube *cube, uint32_t x, uint32_t y, double scale)
{
	char		condition;

	condition = map_condition(cube, x, y, scale);
	if (condition == 'V')
	{
		if (x % cube->map->scale == 0 || y % cube->map->scale == 0)
			mlx_put_pixel(cube->image, x, y, pixel(0, 0, 0, 255));
		else
			mlx_put_pixel(cube->image, x, y, pixel(255, 255, 255, 255));
	}
}

void	two_d_map(void *param)
{
	int			y;
	int			x;
	t_cube		*cube;

	cube = (t_cube *)param;
	x = -1;
	while (++x < cube->map->mini_width)
	{
		y = -1;
		while (++y < cube->map->mini_height)
		{
			if (x < cube->map->draw_width && y < cube->map->draw_height)
				non_grid_lines(cube, x, y, cube->map->scale);
		}
	}
}
