/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:43:54 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/25 18:40:52 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

static void	check_rows_right(t_cube *cube, int row)
{
	int		x;
	char	c;
	char	current;

	x = -1;
	c = 'X';
	while (++x < cube->max_width)
	{
		current = cube->map->map[row][x];
		if (map_valid_chars(current) && edge_conditions(current))
			c = current;
	}
	if (c != '1')
		free_print_exit(cube, 2, 0);
}

static void	check_cols_down(t_cube *cube, int col)
{
	int		y;
	char	c;
	char	current;

	y = -1;
	c = 'X';
	while (++y < cube->max_height)
	{
		current = cube->map->map[y][col];
		if (map_valid_chars(current) && edge_conditions(current))
			c = current;
	}
	if (c == 'X')
		new_map(cube, col);
	else if (c != '1')
		free_print_exit(cube, 2, 0);
}

static void	check_rows_left(t_cube *cube, int row)
{
	int		x;
	char	c;
	char	current;

	x = cube->max_width;
	c = 'X';
	while (--x >= 0)
	{
		current = cube->map->map[row][x];
		if (map_valid_chars(current) && edge_conditions(current))
			c = current;
	}
	if (c != '1')
		free_print_exit(cube, 2, 0);
}

static void	check_cols_up(t_cube *cube, int col)
{
	int		y;
	char	c;
	char	current;

	y = cube->max_height;
	c = 'X';
	while (--y >= 0)
	{
		current = cube->map->map[y][col];
		if (map_valid_chars(current) && edge_conditions(current))
			c = current;
	}
	if (c == 'X')
		new_map(cube, col);
	else if (c != '1')
		free_print_exit(cube, 2, 0);
}

void	check_map_perimeter(t_cube *cube)
{
	int	curr_row;
	int	curr_col;

	curr_row = -1;
	curr_col = -1;
	multiple_start_pos(cube);
	while (++curr_row < cube->max_height)
		check_rows_right(cube, curr_row);
	while (++curr_col < cube->max_width)
		check_cols_down(cube, curr_col);
	curr_row = cube->max_height;
	curr_col = cube->max_width;
	while (--curr_row >= 0)
		check_rows_left(cube, curr_row);
	while (--curr_col >= 0)
		check_cols_up(cube, curr_col);
	find_pl_pos(cube);
	flood_fill(cube, cube->player.opx, cube->player.opy);
}
