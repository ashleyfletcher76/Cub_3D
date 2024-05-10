/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:32:41 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/10 18:52:57 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	if (temp_cube.max_width > 100 || temp_cube.max_height > 100)
		print_error_exit(7);
	return (temp_cube);
}

static void	check_map_helper(t_check *temp_cube,char *line)
{
	check_invalid_chars(temp_cube, line);
	if (!temp_cube->map_start)
		check_details(temp_cube, line);
	if (check_multiple_details(temp_cube))
		temp_cube->map_start = true;
	find_map_width(line, temp_cube);
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
		check_map_helper(temp_cube, line);
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
