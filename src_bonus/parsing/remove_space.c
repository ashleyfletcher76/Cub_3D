/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:13:09 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/07 18:05:16 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	free_new_map(char **new_map, int row)
{
	while (--row >= 0)
		free(new_map[row]);
	free (new_map);
}

static void	free_old_map(t_cube *cube)
{
	int	row;

	row = -1;
	while (++row < cube->max_height)
		free (cube->map->map[row]);
	free (cube->map->map);
}

static void	new_map_helper(t_cube *cube, char **new_map, int row, int col)
{
	int		x;
	int		new_x;

	new_map[row] = ft_calloc(cube->max_width - 1, sizeof(char));
	if (!new_map[row])
	{
		free_new_map(new_map, row);
		free_print_exit_two(cube, NULL, 0);
	}
	x = 0;
	new_x = 0;
	while (x < cube->max_width)
	{
		if (x != col)
			new_map[row][new_x++] = cube->map->map[row][x];
		x++;
	}
}

void	new_map(t_cube *cube, int col)
{
	char	**new_map;
	int		row;

	new_map = malloc(cube->max_height * sizeof(char *));
	if (!new_map)
		free_print_exit(cube, 0, 0);
	row = -1;
	while (++row < cube->max_height)
		new_map_helper(cube, new_map, row, col);
	free_old_map(cube);
	cube->max_width -= 1;
	cube->map->map = new_map;
}
