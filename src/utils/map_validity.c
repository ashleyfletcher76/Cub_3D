/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:43:54 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/17 13:38:51 by asfletch         ###   ########.fr       */
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
		current_width++;
		if (current_width > cube->max_width)
			cube->max_width = current_width;
		i++;
	}
}
