/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:38:44 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/20 12:53:10 by asfletch         ###   ########.fr       */
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
	if (mlx_is_key_down(cube->mlx, MLX_KEY_UP))
		cube->player.py -= 10;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_DOWN))
		cube->player.py += 10;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_LEFT))
		cube->player.px -= 10;
	if (mlx_is_key_down(cube->mlx, MLX_KEY_RIGHT))
		cube->player.px += 10;
	background(cube);
	draw_pixel(cube);
}
