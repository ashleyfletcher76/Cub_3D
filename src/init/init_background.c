/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:10:35 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/20 13:11:05 by asfletch         ###   ########.fr       */
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
			mlx_put_pixel(cube->image, x, y, pixel(0, 0, 0, 255));
			y++;
		}
		x++;
	}
}
