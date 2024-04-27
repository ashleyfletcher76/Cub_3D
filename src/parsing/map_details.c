/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_details.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/04/27 16:52:26 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "structs.h"
#include "cube3d.h"

static void	get_west_east(t_cube *cube, char *line, int index)
{
	int	x;

	x = -1;
	if (index == 0)
	{
		while (line[x] && line[x] != '\n')
		{
			cube->details.east[x] = line[x];
			x++;
		}
	}
	else if (index == 1)
	{
		while (line[x] && line[x] != '\n')
		{
			cube->details.west[x] = line[x];
			x++;
		}
	}
}

static void	get_north_south(t_cube *cube, char *line, int index)
{
	int	x;

	x = -1;
	if (index == 0)
	{
		while (line[x] && line[x] != '\n')
		{
			cube->details.north[x] = line[x];
			x++;
		}
	}
	else if (index == 1)
	{
		while (line[x] && line[x] != '\n')
		{
			cube->details.south[x] = line[x];
			x++;
		}
	}
}

static void	get_floor_roof(t_cube *cube, char *line, int index)
{
	int	x;

	x = -1;
	if (index == 0)
	{
		while (line[x] && line[x] != '\n')
		{
			cube->details.floor[x] = line[x];
			x++;
		}
	}
	else if (index == 1)
	{
		while (line[x] && line[x] != '\n')
		{
			cube->details.ceiling[x] = line[x];
			x++;
		}
	}
}

state_type get_state(char *line)
{
	if (line[0] == 'N')
		return (NORTH);
	else if (line[0] == 'S' && line[1] == 'O')
		return (SOUTH);
	else if (line[0] == 'E' && line[1] == 'A')
		return (EAST);
	else if (line[0] == 'W' && line[1] == 'E')
		return (WEST);
	else if (line[0] == 'F')
		return (FLOOR);
	else if (line[0] == 'C')
		return (CEILING);
	return (MAP);
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
		get_floor_roof(cube, line, 0);
		cube->details_found += 1;
		return (1);
	}
	else if (type == CEILING)
	{
		get_floor_roof(cube, line, 1);
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
		get_north_south(cube, line, 0);
	else if (type == NORTH)
		get_north_south(cube, line, 1);
	else if (type == NORTH)
		get_west_east(cube, line, 0);
	else if (type == NORTH)
		get_west_east(cube, line, 1);
	else if (type == NORTH)
		get_floor_roof(cube, line, 0);
	else if (type == NORTH)
		get_floor_roof(cube, line, 1);
	return (0);
}
