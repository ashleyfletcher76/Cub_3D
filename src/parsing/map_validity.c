/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:43:54 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/18 17:28:58 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

static void	first_and_last_line_check(t_cube *cube, int row)
{
	int	x;

	x = -1;
	while (++x < cube->max_width)
	{
		if (cube->map->map[row][x] != '1' && cube->map->map[row][x] != ' '
			&& (cube->map->map[row][x + 1] != '\n' || cube->map->map[row][x] != '\0'))
		{
			printf("char = %d\n", cube->map->map[row][x]);
			free_print_exit(cube, 2, 0);
		}
	}
}

void	check_map_perimeter(t_cube *cube)
{
	int	curr_index;
	int	curr_row;

	first_and_last_line_check(cube, 0);
	first_and_last_line_check(cube, cube->max_height - 1);
	curr_index = -1;
	curr_row = 0;
	// while (++curr_row < cube->max_height - 1)
	// {
	// 	curr_index = -1;
	// 	while (++curr_index < cube->max_width)
	// 	{
	// 		if (cube->map->map[curr_row][curr_index] == '1')
	// 			check_rows_cols(cube, curr_row, curr_index);
	// 	}
	// }
}
