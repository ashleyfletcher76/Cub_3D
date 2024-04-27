/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:10:10 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/27 17:11:55 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

static char	map_condition(t_cube *cube, uint32_t x, uint32_t y, int i)
{
	return (cube->map->map[y / i][x / i]);
}

static void	non_grid_lines(t_cube *cube, uint32_t x, uint32_t y, int i)
{
	if (map_condition(cube, x, y, i) == '1')
		mlx_put_pixel(cube->image, x, y, pixel(255, 255, 255, 255));
	else if (map_condition(cube, x, y, i) == '0')
		mlx_put_pixel(cube->image, x, y, pixel(0, 0, 0, 255));
	else if (map_condition(cube, x, y, i) == ' ')
		mlx_put_pixel(cube->image, x, y, pixel(128, 128, 128, 255));
	else if (map_condition(cube, x, y, i) == cube->player.d)
		mlx_put_pixel(cube->image, x, y, pixel(0, 0, 0, 255));
	else if (map_condition(cube, x, y, i) == 'V')
		mlx_put_pixel(cube->image, x, y, pixel(0, 0, 0, 255));
	else
		mlx_put_pixel(cube->image, x, y, pixel(128, 128, 128, 255));
}

void	two_d_map(void *param)
{
	int			y;
	int			x;
	int			i;
	t_cube		*cube;

	cube = (t_cube *)param;
	i = MAPSIZE;
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (x % i == 0 || y % i == 0)
				mlx_put_pixel(cube->image, x, y, pixel(0, 0, 0, 0));
			else if (x > cube->max_width * MAPSIZE
				|| y > cube->max_height * MAPSIZE)
				mlx_put_pixel(cube->image, x, y, pixel(0, 0, 0, 0));
			else
				non_grid_lines(cube, x, y, i);
		}
	}
}
