/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:43:38 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/09 15:51:22 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	add_map_conditions(t_cube *cube, char *line, int row)
{
	int	x;

	x = -1;
	if (!line)
		free_print_exit_two(cube, NULL, 0);
	if (get_details(cube, line) == 1)
		return (-1);
	if (check_empty_line_parse(cube, line) == -1)
		return (-1);
	if (cube->details_found == 6)
		cube->map_start = true;
	while (++x < cube->max_width && line[x] != '\0'
		&& line[x] != '\n' && cube->map_start)
		cube->map->map[row][x] = line[x];
	return (0);
}

t_cube	parse_map(t_cube *cube, char *map)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		free_print_exit(cube, 3, 0);
	line = get_next_line(fd);
	y = 0;
	while (line != NULL)
	{
		if (add_map_conditions(cube, line, y) != -1)
			y++;
		free (line);
		line = get_next_line(fd);
	}
	convert_floor(cube);
	convert_ceiling(cube);
	close (fd);
	return (*cube);
}
