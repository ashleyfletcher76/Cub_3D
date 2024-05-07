/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_details.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:17:48 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/07 16:56:56 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs_bonus.h"
#include "cub3d_bonus.h"

void	get_west_east(t_cube *cube, char *line, int index)
{
	int		x;
	char	*east;
	char	*west;

	x = 0;
	if (index == 0)
	{
		east = ft_strdup(line + 3);
		cube->details->east = ft_strtrim(east, "\n");
		free (east);
	}
	else if (index == 1)
	{
		west = ft_strdup(line + 3);
		cube->details->west = ft_strtrim(west, "\n");
		free (west);
	}
}

void	get_north_south(t_cube *cube, char *line, int index)
{
	int		x;
	char	*north;
	char	*south;

	x = 0;
	if (index == 0)
	{
		north = ft_strdup(line + 3);
		cube->details->north = ft_strtrim(north, "\n");
		free (north);
	}
	else if (index == 1)
	{
		south = ft_strdup(line + 3);
		cube->details->south = ft_strtrim(south, "\n");
		free (south);
	}
}

void	get_floor_ceiling(t_cube *cube, char *line, int index)
{
	int		x;
	char	*floor;
	char	*ceiling;

	x = 0;
	if (index == 0)
	{
		floor = ft_strdup(line + 2);
		cube->details->floor = ft_strtrim(floor, "\n");
		free (floor);
	}
	else if (index == 1)
	{
		ceiling = ft_strdup(line + 2);
		cube->details->ceiling = ft_strtrim(ceiling, "\n");
		free (ceiling);
	}
}
