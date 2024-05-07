/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_details.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:50:02 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/07 16:56:26 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs_bonus.h"
#include "cub3d_bonus.h"

static int	check_details_helper(t_cube *temp_cube, t_type type)
{
	if (type == WEST)
	{
		temp_cube->details_found += 1;
		return (1);
	}
	else if (type == FLOOR)
	{
		temp_cube->details_found += 1;
		return (1);
	}
	else if (type == CEILING)
	{
		temp_cube->details_found += 1;
		return (1);
	}
	return (0);
}

int	check_details(t_cube *temp_cube, char *line)
{
	t_type	type;

	type = get_state(line);
	if (type == NORTH)
	{
		temp_cube->details_found += 1;
		return (1);
	}
	else if (type == SOUTH)
	{
		temp_cube->details_found += 1;
		return (1);
	}
	else if (type == EAST)
	{
		temp_cube->details_found += 1;
		return (1);
	}
	if (check_details_helper(temp_cube, type) == 1)
		return (1);
	return (0);
}
