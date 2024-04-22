/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:50:28 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/22 09:29:07 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

int32_t	pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int find_pos(t_cube *cube, char c)
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
		while(++j < cube->max_width)
		{
			if (find_pos(cube, map[i][j]))
			{
				cube->player.px = j * cube->map_size;
				cube->player.py = i * cube->map_size;
				return ;
			}
		}
	}
}

void	draw_pixel(t_cube *cube)
{
	int	x;
	int	y;
	y = 0;
	x = 0;

	while (++x < 10)
	{
		y = 0;
		while (++y < 10)
			mlx_put_pixel(cube->image, cube->player.px + x, cube->player.py + y,
				pixel(255, 255, 0, 255));
	}
}

void	init_player(t_cube *cube)
{
	find_pl_pos(cube);
}
