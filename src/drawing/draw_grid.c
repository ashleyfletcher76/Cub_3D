/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:09:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/20 13:24:37 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

void	draw_grid_basic(t_cube *cube)
{
	int	x;
	int	y;
	int	grid_size;

	x = 40;
	grid_size = 50;
	printf("here\n");
	while (x <= cube->max_width)
	{
		y = 40;
		while (y <= cube->max_height)
		{
			mlx_put_pixel(cube->image, x, y, pixel(255, 255, 255, 255));
			y++;
		}
		x += grid_size;
	}
	y = 40;
	while (y <= cube->max_height)
	{
		x = 40;
		while (x <= cube->max_width)
		{
			mlx_put_pixel(cube->image, x, y, pixel(255, 255, 255, 255));
			x++;
		}
		y += grid_size;
	}
}
