/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:38:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/29 16:51:17 by asfletch         ###   ########.fr       */
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

static void	player_reset(t_cube *cube)
{
	if (mlx_is_key_down(cube->mlx, MLX_KEY_P))
	{
		reset_players_values(cube);
		two_d_map(cube);
		draw_pixel(cube);
	}
}

static void	left_right_keys(t_cube *cube)
{
	if (mlx_is_key_down(cube->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(cube->mlx, MLX_KEY_A))
	{
		cube->player.pa -= 0.03;
		if (cube->player.pa < 0)
			cube->player.pa += 2 * PI;
		cube->player.pdx = cos(cube->player.pa) * 2;
		cube->player.pdy = sin(cube->player.pa) * 2;
	}
	if (mlx_is_key_down(cube->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(cube->mlx, MLX_KEY_D))
	{
		cube->player.pa += 0.03;
		if (cube->player.pa > 2 * PI)
			cube->player.pa -= 2 * PI;
		cube->player.pdx = cos(cube->player.pa) * 2;
		cube->player.pdy = sin(cube->player.pa) * 2;
	}
}

static void	collision_conditions(t_cube *cube, double next_px
	, double next_py, int flag)
{
	if (flag == 0)
	{
		next_px = cube->player.px + cube->player.pdx;
		next_py = cube->player.py + cube->player.pdy;
		if (!is_wall_forward(cube, next_px, next_py, 5))
		{
			cube->player.px = next_px;
			cube->player.py = next_py;
		}
	}
	else if (flag == 1)
	{
		next_px = cube->player.px - cube->player.pdx;
		next_py = cube->player.py - cube->player.pdy;
		if (!is_wall_back(cube, next_px, next_py, 5))
		{
			cube->player.px = next_px;
			cube->player.py = next_py;
		}
	}
}

void	user_input(void *param)
{
	t_cube	*cube;
	double	next_px;
	double	next_py;

	cube = (t_cube *)param;
	next_px = 0.0;
	next_py = 0.0;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(cube->mlx, MLX_KEY_W))
		collision_conditions(cube, next_px, next_py, 0);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(cube->mlx, MLX_KEY_S))
		collision_conditions(cube, next_px, next_py, 1);
	left_right_keys(cube);
	player_reset(cube);
	draw_ray(cube);
	two_d_map(cube);
	draw_pixel(cube);
}
