/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:43:54 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/20 09:17:23 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

static void	check_rows_right(t_cube *cube, int row)
{
	int		x;
	char	c;

	x = -1;
	c = 'X';
	while (++x < cube->max_width)
	{
		if (cube->map->map[row][x] != ' ' && cube->map->map[row][x] != '\0'
			&& cube->map->map[row][x] != '\n')
				c = cube->map->map[row][x];
	}
	if (c != '1')
		free_print_exit(cube, 2, 0);
}

static void	check_cols_down(t_cube *cube, int col)
{
	int		y;
	char	c;

	y = -1;
	c = 'X';
	while (++y < cube->max_height)
	{
		if (cube->map->map[y][col] != ' ' && cube->map->map[y][col] != '\0'
			&& cube->map->map[y][col] != '\n')
				c = cube->map->map[y][col];
	}
	if (c != '1')
		free_print_exit(cube, 2, 0);
}

static void	check_rows_left(t_cube *cube, int row)
{
	int		x;
	char	c;

	x = cube->max_width;
	c = 'X';
	while (--x >= 0)
	{
		if (cube->map->map[row][x] != ' ' && cube->map->map[row][x] != '\0'
			&& cube->map->map[row][x] != '\n')
				c = cube->map->map[row][x];
	}
	if (c != '1')
		free_print_exit(cube, 2, 0);
}


static void	check_cols_up(t_cube *cube, int col)
{
	int		y;
	char	c;

	y = cube->max_height;
	c = 'X';
	while (--y >= 0)
	{
		if (cube->map->map[y][col] != ' ' && cube->map->map[y][col] != '\0'
			&& cube->map->map[y][col] != '\n')
				c = cube->map->map[y][col];
	}
	if (c != '1')
		free_print_exit(cube, 2, 0);
}

void	check_map_perimeter(t_cube *cube)
{
	int	curr_row;
	int	curr_col;

	curr_row = -1;
	curr_col = -1;
	while (++curr_row < cube->max_height - 1)
			check_rows_right(cube, curr_row);
	while (++curr_col < cube->max_width)
			check_cols_down(cube, curr_col);
	curr_row = cube->max_height;
	curr_col = cube->max_width;
	while (--curr_row >= 0)
			check_rows_left(cube, curr_row);
	while (--curr_col >= 0)
			check_cols_up(cube, curr_col);
}
