/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:32:41 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/09 16:25:44 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_check	check_args(int argc, char **argv)
{
	t_check	temp_cube;

	if (argc != 2 || ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == NULL)
		print_error_exit(0);
	temp_cube.max_height = 0;
	temp_cube.max_width = 0;
	temp_cube.map_start = false;
	temp_cube.north = 0;
	temp_cube.south = 0;
	temp_cube.east = 0;
	temp_cube.west = 0;
	temp_cube.floor = 0;
	temp_cube.ceiling = 0;
	check_map(argv[1], &temp_cube);
	check_if_details(&temp_cube);
	return (temp_cube);
}

static int	check_empty_line(t_check *cube, char *line)
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

static void	check_invalid_chars(t_check *temp_cube, char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (correct_chars(line[i]) == -1 && temp_cube->map_start)
		{
			free (line);
			print_error_exit(1);
		}
		i++;
	}
}

void	check_map(char *map, t_check *temp_cube)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		print_error_exit(5);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (check_details(temp_cube, line) == 0
			&& check_multiple_details(temp_cube))
			temp_cube->map_start = true;
		check_invalid_chars(temp_cube, line);
		find_map_width(line, temp_cube);
		if (check_empty_line(temp_cube, line) != -1 && temp_cube->map_start)
		{
			temp_cube->max_height++;
			if (temp_cube->max_height > 100)
				print_error_exit(7);
		}
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
}

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
