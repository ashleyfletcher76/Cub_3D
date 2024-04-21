/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:10:35 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/21 14:52:53 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

void	background(void *param)
{
	uint32_t		x;
	uint32_t		y;
	t_cube			*cube;
	cube = (t_cube *)param;
	int		i = cube->map_size;

	x = 0;
	while (x < cube->image->width)
	{
		y = 0;
		while (y < cube->image->height)
		{
			if (cube->map->map[y / i][x / i] == '1' && x % i != 0 && y % i != 0)
				mlx_put_pixel(cube->image, x, y, pixel(255, 255, 255, 255));
			else if (x % i != 0 && y % i != 0)
				mlx_put_pixel(cube->image, x, y, pixel(0, 0, 0, 255));
			else
				mlx_put_pixel(cube->image, x, y, pixel(0, 0, 0, 0));
			y++;
		}
		x++;
	}
}
