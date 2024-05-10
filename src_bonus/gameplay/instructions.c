/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:34:57 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/10 14:37:39 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	resize(mlx_image_t *str)
{
	mlx_resize_image(str, str->width * 2, str->height * 2);
}

void	put_instructions(t_cube *cube)
{
	cube->instructs.welcome = mlx_put_string(cube->mlx,
		"Welcome to our game!", 500, 500);
	resize(cube->instructs.welcome);
	cube->instructs.start = mlx_put_string(cube->mlx,
		"Press 'P' to play/pause", 500, 550);
	resize(cube->instructs.start);
	cube->instructs.directions = mlx_put_string(cube->mlx,
		"Movement = 'W', 'S', 'A', 'D' 'Up arrow', 'Down arrow'", 500, 650);
	resize(cube->instructs.directions);
	cube->instructs.directions1 = mlx_put_string(cube->mlx,
		"Camera = 'Left arrow', 'Right arrow' or use mouse", 500, 700);
	resize(cube->instructs.directions1);
	cube->instructs.directions2 = mlx_put_string(cube->mlx,
		"To shoot = 'Left click mouse'", 500, 750);
	resize(cube->instructs.directions2);
	cube->instructs.map = mlx_put_string(cube->mlx,
		"To view map = Press 'M'", 500, 800);
	resize(cube->instructs.map);
}
