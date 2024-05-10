/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_details.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:28:11 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/10 18:21:24 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_type	get_state(char *line)
{
	int	i;

	i = 0;
	while (whitespace_skip(line[i]))
		i++;
	if (line[i] == 'N')
		return (NORTH);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		return (SOUTH);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		return (EAST);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		return (WEST);
	else if (line[i] == 'F')
		return (FLOOR);
	else if (line[i] == 'C')
		return (CEILING);
	else if (line[i] == '\0' || line[i] == '\n')
		return (NEWLINE);
	return (END);
}

static int	get_details_helper(t_cube *cube, char *line, t_type type)
{
	if (type == WEST)
	{
		get_west_east(cube, line, 1);
		cube->details_found += 1;
		return (1);
	}
	else if (type == FLOOR)
	{
		get_floor_ceiling(cube, line, 0);
		cube->details_found += 1;
		return (1);
	}
	else if (type == CEILING)
	{
		get_floor_ceiling(cube, line, 1);
		cube->details_found += 1;
		return (1);
	}
	return (0);
}

int	get_details(t_cube *cube, char *line)
{
	t_type	type;

	type = get_state(line);
	if (type == NORTH)
	{
		get_north_south(cube, line, 0);
		cube->details_found += 1;
		return (1);
	}
	else if (type == SOUTH)
	{
		get_north_south(cube, line, 1);
		cube->details_found += 1;
		return (1);
	}
	else if (type == EAST)
	{
		get_west_east(cube, line, 0);
		cube->details_found += 1;
		return (1);
	}
	if (get_details_helper(cube, line, type) == 1)
		return (1);
	return (0);
}
