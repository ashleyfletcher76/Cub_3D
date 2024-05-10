/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:47:46 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/10 18:49:06 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_map_width(char *line, t_check *temp_cube)
{
	int	i;
	int	current_width;

	i = 0;
	current_width = 0;
	while (line[i] != '\n' && line[i] != '\0' && temp_cube->map_start)
	{
		current_width++;
		if (current_width > temp_cube->max_width)
			temp_cube->max_width = current_width;
		if (current_width > 100)
			print_error_exit(7);
		i++;
	}
}

int	check_empty_line(t_check *cube, char *line)
{
	int		x;

	x = -1;
	while (++x < cube->max_width && line[x] != '\0' && line[x] != '\n')
	{
		if (map_valid_chars(line[x]))
			return (1);
	}
	x = -1;
	while (++x < cube->max_height && line[x] != '\0' && line[x] != '\n')
	{
		if (map_valid_chars(line[x]))
			return (1);
	}
	return (-1);
}

void	check_invalid_chars(t_check *temp_cube, char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (correct_chars(line[i]) == -1 && temp_cube->map_start)
		{
			printf("invalid chars\n");
			free (line);
			print_error_exit(1);
		}
		i++;
	}
}
