/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:43:38 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/21 09:16:30 by asfletch         ###   ########.fr       */
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
	y = -1;
	while (line != NULL && ++y < cube->max_height)
	{
		add_map_conditions(cube, line, y);
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
	return (*cube);
}

void	add_map_conditions(t_cube *cube, char *line, int row)
{
	int		x;

	x = -1;
	if (line)
	{
		while (++x < cube->max_width && line[x] != '\0' && line[x] != '\n')
			cube->map->map[row][x] = line[x];
	}
	else
		free_print_exit_two(cube, 0);
}
