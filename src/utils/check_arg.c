/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:47:18 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/17 14:13:58 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

void	check_args(int argc, char **argv, t_cube *cube)
{
	if (argc != 2 || ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == NULL)
		print_error(0);
	cube->max_height = 0;
	cube->max_width = 0;
	check_map(argv[1], cube);
	return ;
}

int	check_map(char *map, t_cube *cube)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	(void)cube;
	while (line != NULL)
	{
		check_invalid_chars(line);
		//cube->max_height++;
		//find_map_width(line, cube);
		line = get_next_line(fd);
		free (line);
	}
	close (fd);
	return (0);
}

static int	correct_chars(char c)
{
	if (c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == ' ')
			return (1);
	return (-1);
}

void	check_invalid_chars(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (correct_chars(line[i]) == -1)
			print_error(1);
		i++;
	}
}

