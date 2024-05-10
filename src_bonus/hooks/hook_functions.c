/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:54:04 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/10 14:30:36 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	close_mini_map(t_cube *cube)
{
	if (cube->map->show_map == false)
		cube->map->show_map = true;
	else
		cube->map->show_map = false;
}

void	handle_fire_two(t_cube *cube)
{
	mlx_delete_image(cube->mlx, cube->gun.gun2);
	cube->gun.gun2 = mlx_texture_to_image(cube->mlx, cube->gun.gun2_t);
	mlx_image_to_window(cube->mlx, cube->gun.gun, 0, 0);
}

void	handle_fire(t_cube *cube)
{
	mlx_delete_image(cube->mlx, cube->gun.gun);
	cube->gun.gun = mlx_texture_to_image(cube->mlx, cube->gun.gun_t);
	mlx_image_to_window(cube->mlx, cube->gun.gun2, 0, 0);
}

void	key_pause(t_cube *cube)
{
	if (cube->pause == 0.5)
	{
		cube->pause = 1;
		mlx_set_cursor_mode(cube->mlx, MLX_MOUSE_HIDDEN);
		delete_instructs_images(cube);
	}
	else
	{
		cube->pause = 0.5;
		mlx_set_cursor_mode(cube->mlx, MLX_MOUSE_NORMAL);
		put_instructions(cube);
	}
}
