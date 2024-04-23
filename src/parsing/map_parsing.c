/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:43:38 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/23 12:09:16 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

t_cube	fill_map(t_cube *cube, char *map)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		free_print_exit(cube, 3, 0);
	line = get_next_line(fd);
	y = 0;
	printf("height = %d\n", cube->max_height);
	while (line != NULL)
	{
		if (add_map_conditions(cube, line, y) != -1)
			y++;
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
	return (*cube);
}

// static int	check_empty_helper(t_cube *cube, char *line, int col)
// {
// 	int	row;

// 	row = -1;
// 	while (++row < cube->max_height)
// 	{
// 		if (cube->map->map[row][col] != ' ')
// 			return (0);
// 	}
// 	return (1);
// }

// int	check_empty_col(t_cube *cube, char *line)
// {
// 	int	col;

// 	col = -1;
// 	while (++col < cube->max_width)
// 	{
// 		if (check_empty_helper(cube, col))
// 			return (col);
// 	}
// 	return (-1);
// }

int	add_map_conditions(t_cube *cube, char *line, int row)
{
	int	x;

	x = -1;
	if (line)
	{
		if (check_empty_line(cube, line) == -1)
			return (-1);
		while (++x < cube->max_width && line[x] != '\0' && line[x] != '\n')
			cube->map->map[row][x] = line[x];
	}
	else
		free_print_exit_two(cube, 0);
	return (0);
}
