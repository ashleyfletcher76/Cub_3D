/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:38:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/21 15:11:30 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

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
	if (mlx_is_key_down(cube->mlx, MLX_KEY_UP) || mlx_is_key_down(cube->mlx, MLX_KEY_W))
	{
		cube->player.px += cube->player.pdx;
		cube->player.py += cube->player.pdy;
	}
	if (mlx_is_key_down(cube->mlx, MLX_KEY_DOWN) || mlx_is_key_down(cube->mlx, MLX_KEY_S))
	{
		cube->player.px -= cube->player.pdx;
		cube->player.py -= cube->player.pdy;
	}
	if (mlx_is_key_down(cube->mlx, MLX_KEY_LEFT) || mlx_is_key_down(cube->mlx, MLX_KEY_A))
	{
		cube->player.pa -= 0.1;
		if (cube->player.pa < 0)
			cube->player.pa += 2 * PI;
		cube->player.pdx = cos(cube->player.pa) * 5;
		cube->player.pdy = sin(cube->player.pa) * 5;
	}
	if (mlx_is_key_down(cube->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(cube->mlx, MLX_KEY_D))
	{
		cube->player.pa += 0.1;
		if (cube->player.pa < 0)
			cube->player.pa -= 2 * PI;
		cube->player.pdx = cos(cube->player.pa) * 5;
		cube->player.pdy = sin(cube->player.pa) * 5;
	}
	background(cube);
	draw_pixel(cube);
}
