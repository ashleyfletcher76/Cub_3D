/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:38:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/06 11:22:40 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

void	user_input(mlx_key_data_t keys, void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (keys.action == MLX_PRESS || keys.action == MLX_REPEAT)
	{
		if (keys.key == KEY_M)
			close_mini_map(cube);
	}
}

void	user_input_two(void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	read_keys(cube);
	draw_ray(cube);
	if (cube->map->show_map == true)
	{
		two_d_map(cube);
		draw_pixel(cube);
	}
}

void	read_keys(t_cube *cube)
{
	if (mlx_is_key_down(cube->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(cube->mlx, MLX_KEY_A))
		key_left(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(cube->mlx, MLX_KEY_D))
		key_right(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(cube->mlx, MLX_KEY_W))
		key_up(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(cube->mlx, MLX_KEY_S))
		key_down(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_P))
		reset_players_values(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cube->mlx);
}
