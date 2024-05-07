/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:38:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/07 09:28:17 by asfletch         ###   ########.fr       */
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
	mlx_image_to_window(cube->mlx, cube->guns.gun1, 0, 0);
	// mlx_image_to_window(cube->mlx, cube->img2, 0, 0);
	// mlx_image_to_window(cube->mlx, cube->img3, 0, 0);
}

void	read_keys(t_cube *cube)
{
	if (mlx_is_key_down(cube->mlx, MLX_KEY_LEFT))
		key_left(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_RIGHT))
		key_right(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_A))
		key_a(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_D))
		key_d(cube);
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
