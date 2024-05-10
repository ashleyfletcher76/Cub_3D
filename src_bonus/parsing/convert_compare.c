/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_compare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:09:10 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/07 18:04:31 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	convert_integers(t_cube *cube, char **rgb, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		cube->details->gen_rgb[i] = ft_atoi(rgb[i]);
}

static void	convert_helper(t_cube *cube, char **rgb, int count)
{
	cube->details->gen_rgb = ft_calloc(count + 1, sizeof(int *));
	if (!rgb)
	{
		free_rgb(rgb);
		free_print_exit_two(cube, NULL, 1);
	}
	convert_integers(cube, rgb, count);
	free_rgb(rgb);
}

void	convert_floor(t_cube *cube)
{
	char	**rgb;
	int		count;

	rgb = ft_split(cube->details->floor, ',');
	if (!rgb)
		free_print_exit_two(cube, NULL, 1);
	count = count_double(rgb);
	if (count != 3)
	{
		free_rgb (rgb);
		free_print_exit_two(cube, NULL, 1);
	}
	if (check_invalid_integers(rgb) == -1)
	{
		free_rgb(rgb);
		free_print_exit_two(cube, NULL, 2);
	}
	convert_helper(cube, rgb, count);
	convert_to_rgb(cube, 0, count);
}

void	convert_ceiling(t_cube *cube)
{
	char	**rgb;
	int		count;

	rgb = ft_split(cube->details->ceiling, ',');
	if (!rgb)
		free_print_exit_two(cube, NULL, 1);
	count = count_double(rgb);
	if (count != 3)
	{
		free_rgb (rgb);
		free_print_exit_two(cube, NULL, 1);
	}
	if (check_invalid_integers(rgb) == -1)
	{
		free_rgb(rgb);
		free_print_exit_two(cube, NULL, 2);
	}
	convert_helper(cube, rgb, count);
	convert_to_rgb(cube, 1, count);
}
