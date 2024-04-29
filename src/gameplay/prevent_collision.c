/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prevent_collision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:05:38 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/29 11:25:42 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

int	is_wall_back(t_cube *cube, int x, int y)
{
	int	grid_x;
	int	grid_y;

	grid_x = (x - 0) / MAPSIZE;
	grid_y = (y - 0) / MAPSIZE;
	if (grid_x >= 0 && grid_x < cube->max_width && grid_y >= 0
		&& grid_y < cube->max_height)
		return (cube->map->map[grid_y][grid_x] == '1');
	return (0);
}

int	is_wall_forward(t_cube *cube, int x, int y)
{
	int	grid_x;
	int	grid_y;

	grid_x = (x + 0) / MAPSIZE;
	grid_y = (y + 0) / MAPSIZE;
	if (grid_x >= 0 && grid_x < cube->max_width && grid_y >= 0
		&& grid_y < cube->max_height)
		return (cube->map->map[grid_y][grid_x] == '1');
	return (0);
}
