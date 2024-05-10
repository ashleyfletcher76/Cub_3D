/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:05:11 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/08 15:30:05 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void	calculate_dimensions(t_cube *cube)
{
	int	baseline_width;
	int	baseline_height;

	baseline_width = cube->max_width * PIXEL_PER_CELL;
	baseline_height = cube->max_height * PIXEL_PER_CELL;
	cube->map->mini_width = fmax(MIN_MAP_SIZE,
			fmin(baseline_width, MAX_MAP_SIZE));
	cube->map->mini_height = fmax(MIN_MAP_SIZE,
			fmin(baseline_height, MAX_MAP_SIZE));
}

static void	cube_helper(t_cube *cube)
{
	cube->map->mini_width = 0;
	cube->map->mini_width = 0;
	cube->map->mini_height = 0;
	cube->map->scale = 0;
	cube->map->draw_width = 0;
	cube->map->draw_height = 0;
	cube->map->scale_width = 0;
	cube->map->scale_height = 0;
	cube->map->show_map = false;
}

int32_t	init_2d_map(t_cube *cube)
{
	cube_helper(cube);
	calculate_dimensions(cube);
	init_mini_values(cube);
	return (EXIT_SUCCESS);
}
