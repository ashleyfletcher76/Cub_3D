/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:05:14 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/10 14:11:15 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_instructions(t_cube *cube)
{
	cube->instructs.welcome = NULL;
	cube->instructs.start = NULL;
	cube->instructs.directions = NULL;
	cube->instructs.directions1 = NULL;
	cube->instructs.directions2 = NULL;
	cube->instructs.map = NULL;
}

void	delete_instructs_images(t_cube *cube)
{
	if (cube->instructs.welcome)
		mlx_delete_image(cube->mlx, cube->instructs.welcome);
	if (cube->instructs.start)
		mlx_delete_image(cube->mlx, cube->instructs.start);
	if (cube->instructs.directions)
		mlx_delete_image(cube->mlx, cube->instructs.directions);
	if (cube->instructs.directions1)
		mlx_delete_image(cube->mlx, cube->instructs.directions1);
	if (cube->instructs.directions2)
		mlx_delete_image(cube->mlx, cube->instructs.directions2);
	if (cube->instructs.map)
		mlx_delete_image(cube->mlx, cube->instructs.map);
	init_instructions(cube);
}
