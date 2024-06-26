/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:50:28 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/10 15:29:19 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
				cube->player.opx = j + 0.5;
				cube->player.opy = i + 0.5;
				cube->player.px = j + 0.5;
				cube->player.py = i + 0.5;
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
	cube->player_default.pa = cube->player.pa;
}

void	init_player(t_cube *cube)
{
	find_pl_pos(cube);
	if (cube->player.d == 'E')
		cube->player.pa = 0;
	if (cube->player.d == 'N')
		cube->player.pa = 90;
	if (cube->player.d == 'W')
		cube->player.pa = 180;
	if (cube->player.d == 'S')
		cube->player.pa = 270;
	cube->player.pdx = cos(degtorad(cube->player.pa));
	cube->player.pdy = -sin(degtorad(cube->player.pa));
	init_default_player(cube);
}
