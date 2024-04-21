/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:50:28 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/21 13:32:57 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

int32_t	pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_pixel(t_cube *cube)
{
	int	x;
	int	y;

	x = 0;
	while (++x < 5)
	{
		y = 0;
		while (++y < 5)
			mlx_put_pixel(cube->image, cube->player.px + x, cube->player.py + y,
				pixel(255, 2555, 255, 255));
	}
}

void	init_player(t_cube *cube)
{
	cube->player.py = 10;
	cube->player.px = 10;
}
