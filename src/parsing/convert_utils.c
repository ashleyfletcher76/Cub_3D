/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:48:42 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/29 15:08:06 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

void	compare_textures(t_cube *cube)
{
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;

	NO = "./path_to_the_north_texture";
	SO = "./path_to_the_south_texture";
	EA = "./path_to_the_east_texture";
	WE = "./path_to_the_west_texture";
	if (ft_strcmp(cube->details->north, NO) != 0)
		free_print_exit_two(cube, NULL, 1);
	if (ft_strcmp(cube->details->south, SO) != 0)
		free_print_exit_two(cube, NULL, 1);
	if (ft_strcmp(cube->details->east, EA) != 0)
		free_print_exit_two(cube, NULL, 1);
	if (ft_strcmp(cube->details->west, WE) != 0)
		free_print_exit_two(cube, NULL, 1);
}

int	count_double(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
		i++;
	return (i);
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
			if (rgb[i][j] < '0' && rgb[i][j] > '9')
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

void	convert_integers(t_cube *cube, char **rgb, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		cube->details->gen_rgb[i] = ft_atoi(rgb[i]);
}
