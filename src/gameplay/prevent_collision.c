/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prevent_collision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:05:38 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/27 17:12:09 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

int	is_wall(t_cube *cube, int x, int y)
{
	int	grid_x;
	int	grid_y;

	grid_x = x / MAPSIZE;
	grid_y = y / MAPSIZE;
	if (grid_x >= 0 && grid_x < cube->max_width && grid_y >= 0
		&& grid_y < cube->max_height)
		return (cube->map->map[grid_y][grid_x] == '1');
	return (0);
}
