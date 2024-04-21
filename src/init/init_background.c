/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:10:35 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/21 14:47:16 by muhakose         ###   ########.fr       */
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
	x = 0;
	while (x < cube->image->width)
	{
		y = 0;
		while (y < cube->image->height)
		{
			if (cube->map->map[y + 1 / cube->map_size][x + 1 / cube->map_size] == '1')
				mlx_put_pixel(cube->image, x, y, pixel(255, 255, 255, 255));
			else
				mlx_put_pixel(cube->image, x, y, pixel(0, 0, 0, 255));
			y++;
		}
		x++;
	}
}
