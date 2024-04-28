/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:48:42 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/28 16:44:21 by asfletch         ###   ########.fr       */
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

void	null_ceiling(t_cube *cube)
{
	int	i;

	i = -1;
	while (++i < cube->details->int_count)
		cube->details->ceiling_rgb[i] = 0;
}

int	count_double(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
		i++;
	return (i);
}

void	convert_integers(t_cube *cube, char **rgb, int count, int flag)
{
	int	i;

	i = -1;
	if (flag == 0)
	{
		while (++i < count)
			cube->details->floor_rgb[i] = ft_atoi(rgb[i]);
	}
	else
	{
		while (++i < count)
			cube->details->ceiling_rgb[i] = ft_atoi(rgb[i]);
	}
}
