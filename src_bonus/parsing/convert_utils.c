/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:48:42 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/07 16:56:42 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs_bonus.h"
#include "cub3d_bonus.h"

static int	whitespace_skip(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\v' || c == '\r')
		return (true);
	return (false);
}

int	check_invalid_integers(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			while (whitespace_skip(rgb[i][j]))
				j++;
			if (rgb[i][j] < '0' || rgb[i][j] > '9')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	convert_to_rgb(t_cube *cube, int flag, int count)
{
	if (check_numbers(cube->details->gen_rgb, count) == -1)
	{
		free (cube->details->gen_rgb);
		free_print_exit_two(cube, NULL, 2);
	}
	if (flag == 0)
		cube->details->floor_rgb = pixel(cube->details->gen_rgb[0],
				cube->details->gen_rgb[1], cube->details->gen_rgb[2], 255);
	else
		cube->details->ceiling_rgb = pixel(cube->details->gen_rgb[0],
				cube->details->gen_rgb[1], cube->details->gen_rgb[2], 255);
	free (cube->details->gen_rgb);
}
