/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:50:28 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/25 10:10:36 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

int32_t	pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	find_pos(t_cube *cube, char c)
{
	if (c == 'N')
	{
		cube->player.d = 'N';
		return (true);
	}
	else if (c == 'S')
	{
		cube->player.d = 'S';
		return (true);
	}
	else if (c == 'E')
	{
		cube->player.d = 'E';
		return (true);
	}
	else if (c == 'W')
	{
		cube->player.d = 'W';
		return (true);
	}
	return (false);
}

void	find_pl_pos(t_cube *cube)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	map = cube->map->map;
	while (++i < cube->max_height)
	{
		j = -1;
		while (++j < cube->max_width)
		{
			if (find_pos(cube, map[i][j]))
			{
				cube->player.opx = j;
				cube->player.opy = i;
				cube->player.px = j * cube->map_size;
				cube->player.py = i * cube->map_size;
				return ;
			}
		}
	}
}

void	init_default_player(t_cube *cube)
{
	cube->player_default.px = cube->player.px;
	cube->player_default.py = cube->player.py;
	cube->player_default.pdx = cube->player.pdx;
	cube->player_default.pdy = cube->player.pdy;
}

void	init_player(t_cube *cube)
{
	find_pl_pos(cube);
	cube->player.pdx = cos(cube->player.pa) * 5;
	cube->player.pdy = sin(cube->player.pa) * 5;
	init_default_player(cube);
}
