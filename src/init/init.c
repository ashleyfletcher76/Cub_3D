/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:14:15 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/17 10:27:25 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "structs.h"

int32_t	init_mlx(t_cube *cube)
{
	cube->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!cube->mlx)
		return (EXIT_FAILURE);
	cube->image = mlx_new_image(cube->mlx, 1920, 1080);
	if (!cube->image)
	{
		mlx_delete_image(cube->mlx, cube->image);
		mlx_close_window(cube->mlx);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(cube->mlx, cube->image, 0, 0) == -1)
	{
		mlx_close_window(cube->mlx);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
