/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_details.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:18:48 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/27 14:10:33 by muhakose         ###   ########.fr       */
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
	else if (line[0] == 'S')
		return (SOUTH);
	else if (line[0] == 'E')
		return (EAST);
	else if (line[0] == 'W')
		return (WEST);
	else if (line[0] == 'F')
		return (FLOOR);
	else if (line[0] == 'C')
		return (CEILING);
	return (MAP);
}


int	get_details(t_cube *cube, char *line)
{
	state_type type;

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
