/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:11:26 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/09 12:25:36 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	check_multiple_portal(char *line)
{
	int			i;
	int			j;
	int			checker;
	const char	*str;

	i = 0;
	checker = 0;
	str = "X";
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

static int	check_multiple_start(char *line)
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
	int	check_start;
	int	check_portal;

	y = -1;
	check_start = 0;
	check_portal = 0;
	while (++y < cube->max_height)
	{
		check_start += check_multiple_start(cube->map->map[y]);
		check_portal += check_multiple_portal(cube->map->map[y]);
	}
	if (check_start != 1)
	{
		printf("Multiple start pos or none\n");
		free_print_exit(cube, 2, 0);
	}
	if (check_portal > 1)
	{
		printf("Multiple portal pos\n");
		free_print_exit(cube, 2, 0);
	}
}
