/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:28:27 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/25 13:26:49 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

void	flood_fill(char **map, t_cube *cube, int x, int y)
{
	if (x < 0 || y < 0)
	{
		printf("Fill 1\n");
		free_print_exit(cube, 2, 0);
	}
	if (x >= cube->max_width || y >= cube->max_height)
	{
		printf("Fill 2\n");
		free_print_exit(cube, 2, 0);
	}
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, cube, x + 1, y);
	flood_fill(map, cube, x - 1, y);
	flood_fill(map, cube, x, y + 1);
	flood_fill(map, cube, x, y - 1);
}
