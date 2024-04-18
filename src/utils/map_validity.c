/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:43:54 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/18 08:47:12 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

void	find_map_width(char *line, t_cube *cube)
{
	int	i;
	int	current_width;

	i = 0;
	current_width = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != ' ')
			current_width++;
		if (current_width > cube->max_width)
			cube->max_width = current_width;
		i++;
	}
}

int	check_map_perimeter(char *line)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] != '1')
		return (-1);
	start = i;
	while (line[i] != '\n' && line[i] != '\0' && line[i] == '1')
		i++;
	end = i - 1;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line [i] == '1')
		{
			if (i - end > 1)
				return (-1);
			end = i;
		}
		i++;
	}
	while (line[end] == ' ')
		end--;
	if (line[end] != '1')
		return (-1);
	return (1);
}
