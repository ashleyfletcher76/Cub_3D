/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_d_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:35:36 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/05 11:18:44 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

static char map_condition(t_cube *cube, uint32_t x, uint32_t y, double scale)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / scale);
	map_y = (int)(y / scale);
	return (cube->map->map[map_y][map_x]);
}

static void non_grid_lines(t_cube *cube, uint32_t x, uint32_t y, double scale)
{
	char		condition;
	uint32_t	color;

	condition = map_condition(cube, x, y, scale);
	color = 0;
	if (condition == '1')
		color = pixel(255, 255, 255, 0);
	else if (condition == 'V')
		color = pixel(255, 255, 255, 255);
	else if (condition == ' ')
		color = pixel(128, 128, 128, 0);
	else
		color = pixel(128, 128, 128, 0);
	mlx_put_pixel(cube->image, x, y, color);
}

static void	init_mini_values(t_cube *cube)
{
	cube->map->scale_width = cube->map->mini_width / (double)cube->max_width;
	cube->map->scale_height = cube->map->mini_height / (double)cube->max_height;
	cube->map->scale = fmin(cube->map->scale_width, cube->map->scale_height);
	cube->map->draw_width = cube->max_width * cube->map->scale;
	cube->map->draw_height = cube->max_height * cube->map->scale;
}

void	two_d_map(void *param)
{
	int			y;
	int			x;
	t_cube		*cube;

	cube = (t_cube *)param;
	init_mini_values(cube);
	x = -1;
	while (++x < cube->map->mini_width)
	{
		y = -1;
		while (++y < cube->map->mini_height)
		{
			if (x % cube->map->scale == 0 || y % cube->map->scale == 0)
				mlx_put_pixel(cube->image, x, y, pixel(0, 0, 0, 0));
			else if (x < cube->map->draw_width && y < cube->map->draw_height)
				non_grid_lines(cube, x, y, cube->map->scale);
		}
	}
}
