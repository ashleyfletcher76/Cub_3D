/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:49:46 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/26 16:35:47 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

static int	check_multiple(char *line)
{
	int			i;
	int			j;
	int			checker;
	const char	*str;

	i = 0;
	checker = 0;
	str = "NSWE";
	while (line[i])
	{
		j = 0;
		while (str[j])
		{
			if (line[i] == str[j])
				checker++;
			j++;
		}
		i++;
	}
	return (checker);
}

void	multiple_start_pos(t_cube *cube)
{
	int	y;
	int	checker;

	y = -1;
	checker = 0;
	while (++y < cube->max_height)
	{
		checker += check_multiple(cube->map->map[y]);
		if (checker != 1)
			free_print_exit(cube, 2, 0);
	}
}
