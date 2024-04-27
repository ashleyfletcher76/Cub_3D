/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_details.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:17:48 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/27 16:45:29 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

void	get_west_east(t_cube *cube, char *line, int index)
{
	int	x;

	x = 0;
	if (index == 0)
		cube->details->east = ft_strdup(line + 3);
	else if (index == 1)
		cube->details->west = ft_strdup(line + 3);
}

void	get_north_south(t_cube *cube, char *line, int index)
{
	int	x;

	x = 0;
	if (index == 0)
		cube->details->north = ft_strdup(line + 3);
	else if (index == 1)
		cube->details->south = ft_strdup(line + 3);
}

void	get_floor_roof(t_cube *cube, char *line, int index)
{
	int	x;

	x = 0;
	if (index == 0)
		cube->details->floor = ft_strdup(line + 2);
	else if (index == 1)
		cube->details->ceiling = ft_strdup(line + 2);
}
