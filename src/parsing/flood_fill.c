/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:28:27 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/25 12:00:40 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

void	flood_fill(char **map, t_cube *cube, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (x >= cube->max_width || y >= cube->max_height)
	{
		printf("Boundary breach attempt at x = %d, y = %d, width = %d, height = %d\n", x, y, cube->max_width, cube->max_height);
		return ;
	}
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, cube, x + 1, y);
	flood_fill(map, cube, x - 1, y);
	flood_fill(map, cube, x, y + 1);
	flood_fill(map, cube, x, y - 1);
}
