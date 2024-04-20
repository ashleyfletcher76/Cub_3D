/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:43:38 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/20 16:40:05 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

t_cube	fill_map(t_cube *cube, char *map)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		print_error_exit(5);
	line = get_next_line(fd);
	y = -1;
	while (line != NULL && ++y < cube->max_height)
	{
		add_map_conditions(cube, line, y);
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
	return (*cube);
}

static int	count(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ')
			count++;
		i++;
	}
	return (count);
}

static char	*create_new_string(char *line)
{
	char	*newline;
	int		len;
	int		j;
	int		i;

	i = 0;
	j = 0;
	len = count(line);
	newline = malloc(sizeof(char *) * len + 1);
	if (!newline)
		return (NULL);
	while (line[i])
	{
		if (line[i] != ' ')
			newline[j++] = line[i];
		i++;
	}
	newline[j] = '\0';
	return (newline);
}

void	add_map_conditions(t_cube *cube, char *line, int row)
{
	int		x;
	char	*newline;

	x = -1;
	newline = create_new_string(line);
	//newline = line;
	if (newline)
	{
		while (++x < cube->max_width && line[x] != '\0' && line[x] != '\n')
			cube->map->map[row][x] = newline[x];
		free (newline);
	}
}
