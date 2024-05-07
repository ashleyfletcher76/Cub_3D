/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_d_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:35:36 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/07 16:55:46 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs_bonus.h"
#include "cub3d_bonus.h"

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

	condition = map_condition(cube, x, y, scale);
	if (condition == 'V')
	{
		if (x % cube->map->scale == 0 || y % cube->map->scale == 0)
			mlx_put_pixel(cube->image, x, y, pixel(0, 0, 0, 255));
		else
			mlx_put_pixel(cube->image, x, y, pixel(255, 255, 255, 255));
	}
	else if (condition == 'L')
		mlx_put_pixel(cube->image, x, y, pixel(160, 32, 240, 255));
	else if (condition == 'Z')
		mlx_put_pixel(cube->image, x, y, pixel(255, 0, 0, 255));
}

static void	correct_pixel_scale(t_cube *cube)
{
	double	total_area;
	double	base_scale;

	total_area = cube->max_width * cube->max_height;
	base_scale = sqrt(total_area) / 150;
	cube->map->pixel_scale = fmax(5, fmin(base_scale, 40));
}

static void	init_mini_values(t_cube *cube)
{
	cube->map->scale_width = cube->map->mini_width / (double)cube->max_width;
	cube->map->scale_height = cube->map->mini_height / (double)cube->max_height;
	cube->map->scale = fmin(cube->map->scale_width, cube->map->scale_height);
	cube->map->draw_width = cube->max_width * cube->map->scale;
	cube->map->draw_height = cube->max_height * cube->map->scale;
	correct_pixel_scale(cube);
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
			if (x < cube->map->draw_width && y < cube->map->draw_height)
				non_grid_lines(cube, x, y, cube->map->scale);
		}
	}
}
