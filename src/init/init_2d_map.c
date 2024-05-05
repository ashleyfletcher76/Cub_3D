/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:05:11 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/03 18:04:41 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

static int	calculate_scale(t_cube *cube)
{
	int	max;
	int	scale;

	max = fmax(cube->max_width, cube->max_height);
	scale = max / 4;
	if (scale == 0)
		scale = 1;
	return (scale);
}

static void	calculate_dimensions(t_cube *cube, int scale)
{
	if (scale >= 1 && scale <= 5)
	{
		cube->map->mini_width = 300;
		cube->map->mini_height = 300;
	}
	else if (scale >= 6 && scale <= 10)
	{
		cube->map->mini_width = 400;
		cube->map->mini_height = 400;
	}
	else if (scale >= 11 && scale <= 15)
	{
		cube->map->mini_width = 500;
		cube->map->mini_height = 500;
	}
	else if (scale >= 16 && scale <= 20)
	{
		cube->map->mini_width = 600;
		cube->map->mini_height = 600;
	}
	else
	{
		cube->map->mini_width = 700;
		cube->map->mini_height = 700;
	}
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
	cube->map->show_map = true;
}

int32_t	init_2d_map(t_cube *cube)
{
	int	scale;

	cube_helper(cube);
	scale = calculate_scale(cube);
	calculate_dimensions(cube, scale);
	return (EXIT_SUCCESS);
}
