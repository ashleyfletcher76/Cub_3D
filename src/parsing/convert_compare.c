/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_compare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:09:10 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/29 16:30:15 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

int	check_numbers(int *rgb, int count)
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
		printf("here\n");
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
