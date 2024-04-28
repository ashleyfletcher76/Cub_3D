/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_compare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:09:10 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/28 13:50:46 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

static int	check_numbers(int *rgb, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (-1);
	}
	return (0);
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
	cube->details->floor_rgb = ft_calloc(count + 1, sizeof(int *));
	if (!cube->details->floor_rgb)
		free_print_exit_two(cube, NULL, 1);
	cube->details->floor_rgb[count] = '\0';
	cube->details->int_count = count;
	convert_integers(cube, rgb, count, 0);
	free_rgb (rgb);
	if (check_numbers(cube->details->floor_rgb, count) == -1)
		free_print_exit_two(cube, NULL, 2);
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
	cube->details->ceiling_rgb = ft_calloc(count + 1, sizeof(int *));
	if (!cube->details->ceiling_rgb)
		free_print_exit_two(cube, NULL, 1);
	cube->details->ceiling_rgb[count] = '\0';
	cube->details->int_count = count;
	convert_integers(cube, rgb, count, 1);
	free_rgb (rgb);
	if (check_numbers(cube->details->ceiling_rgb, count) == -1)
	{
		null_ceiling(cube);
		free_print_exit_two(cube, NULL, 2);
	}
}
