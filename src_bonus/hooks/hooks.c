/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:38:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/07 16:55:57 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs_bonus.h"
#include "cub3d_bonus.h"

void	user_input(mlx_key_data_t keys, void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (keys.action == MLX_PRESS)
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

void	mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void* param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	(void)button; // if equals to 0 left click 1 right clik 2 middle click
	(void)action;
	(void)mods;
}

void	cursour_hook(double xpos, double ypos, void* param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (xpos < WIDTH && xpos > 0 && ypos < HEIGHT && ypos > 0)
	{
		if ((int)xpos > WIDTH / 2)
			mouse_right(cube);
		else if (xpos < WIDTH / 2)
			mouse_left(cube);
		cube->mouse.y = ypos;
		cube->mouse.x = xpos;
		mlx_set_mouse_pos(cube->mlx, WIDTH / 2, HEIGHT / 2);
	}
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
	{
		print_error_exit(6);
		mlx_close_window(cube->mlx);
	}
}
