/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:47:18 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/26 15:11:36 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

t_cube	check_args(int argc, char **argv)
{
	t_cube	temp_cube;

	if (argc != 2 || ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == NULL)
		print_error_exit(0);
	temp_cube.max_height = 0;
	temp_cube.max_width = 0;
	temp_cube.width_nospace = 0;
	temp_cube = check_map(argv[1], &temp_cube);
	return (temp_cube);
}

int	check_empty_line(t_cube *cube, char *line)
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

t_cube	check_map(char *map, t_cube *temp_cube)
{
	int			fd;
	char		*line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		print_error_exit(5);
	line = get_next_line(fd);
	while (line != NULL)
	{
		check_invalid_chars(line);
		find_map_width(line, temp_cube);
		if (check_empty_line(temp_cube, line) != -1)
			temp_cube->max_height++;
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
	return (*temp_cube);
}

void	check_invalid_chars(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (correct_chars(line[i]) == -1)
		{
			free (line);
			print_error_exit(1);
		}
		i++;
	}
}

void	find_map_width(char *line, t_cube *cube)
{
	int	i;
	int	width_nospace;
	int	current_width;

	i = 0;
	current_width = 0;
	width_nospace = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != ' ')
			width_nospace++;
		current_width++;
		if (current_width > cube->max_width)
			cube->max_width = current_width;
		i++;
	}
}
