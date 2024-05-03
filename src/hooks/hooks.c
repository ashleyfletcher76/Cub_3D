/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:38:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/03 17:42:22 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

void	hook(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cube->mlx);
}


void	user_input(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	read_keys(cube);
	//two_d_map(cube);
	//draw_pixel(cube);
	draw_ray(cube);
}
