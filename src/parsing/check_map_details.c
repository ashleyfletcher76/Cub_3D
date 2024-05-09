/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_details.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:50:02 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/09 16:22:14 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_empty_line_parse(t_cube *cube, char *line)
{
	int		x;

	x = -1;
	while (++x < cube->max_width && line[x] != '\0' && line[x] != '\n')
	{
		if (map_valid_chars(line[x]))
			return (1);
	}
	x = -1;
	while (++x < cube->max_height && line[x] != '\0' && line[x] != '\n')
	{
		if (map_valid_chars(line[x]))
			return (1);
	}
	return (-1);
}

int	check_multiple_details(t_check *temp_cube)
{
	if (temp_cube->north == 1 && temp_cube->south == 1
		&& temp_cube->east == 1 && temp_cube->west == 1
		&& temp_cube->floor == 1 && temp_cube->ceiling == 1)
		return (1);
	if (temp_cube->north > 1 || temp_cube->south > 1
		|| temp_cube->east > 1 || temp_cube->west > 1
		|| temp_cube->floor > 1 || temp_cube->ceiling > 1)
		print_error_exit(8);
	return (0);
}

static int	check_details_helper(t_check *temp_cube, t_type type)
{
	if (type == WEST)
	{
		temp_cube->west += 1;
		return (1);
	}
	else if (type == FLOOR)
	{
		temp_cube->floor += 1;
		return (1);
	}
	else if (type == CEILING)
	{
		temp_cube->ceiling += 1;
		return (1);
	}
	return (0);
}

int	check_details(t_check *temp_cube, char *line)
{
	t_type	type;

	type = get_state(line);
	if (type == NORTH)
	{
		temp_cube->north += 1;
		return (1);
	}
	else if (type == SOUTH)
	{
		temp_cube->south += 1;
		return (1);
	}
	else if (type == EAST)
	{
		temp_cube->east += 1;
		return (1);
	}
	if (check_details_helper(temp_cube, type) == 1)
		return (1);
	return (0);
}
