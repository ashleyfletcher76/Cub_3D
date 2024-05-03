/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:05:11 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/03 17:54:04 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

static int	calculate_scale(t_cube *cube)
{
	int	max;
	int	scale;

	max = fmax(cube->max_width, cube->max_height);
	scale = max / 4;
	if (scale == 0)
		scale = 1;
	return (scale);
}

static void	calculate_dimensions(t_cube *cube, int scale)
{
	if (scale >= 1 && scale <= 5)
	{
		cube->map->mini_width = 300;
		cube->map->mini_height = 300;
	}
	else if (scale >= 6 && scale <= 10)
	{
		cube->map->mini_width = 400;
		cube->map->mini_height = 400;
	}
	else if (scale >= 11 && scale <= 15)
	{
		cube->map->mini_width = 500;
		cube->map->mini_height = 500;
	}
	else if (scale >= 16 && scale <= 20)
	{
		cube->map->mini_width = 600;
		cube->map->mini_height = 600;
	}
	else
	{
		cube->map->mini_width = 700;
		cube->map->mini_height = 700;
	}
}

int32_t	init_2d_map(t_cube *cube)
{
	int	scale;

	scale = calculate_scale(cube);
	printf("scale = %d\n", scale);
	calculate_dimensions(cube, scale);
	//cube->mini = mlx_new_image(cube->mlx, cube->map->mini_width, cube->map->mini_height);
	//if (!cube->mini)
	//{
	//	mlx_delete_image(cube->mlx, cube->image);
	//	mlx_delete_image(cube->mlx, cube->mini);
	//	mlx_close_window(cube->mlx);
	//	return (EXIT_FAILURE);
	//}
	//if (mlx_image_to_window(cube->mlx, cube->mini, 0, 0) == -1)
	//{
	//	mlx_close_window(cube->mlx);
	//	return (EXIT_FAILURE);
	//}
	return (EXIT_SUCCESS);
}

// static int	calculate_scale(t_cube *cube)
// {
// 	int	max;
// 	int	scale;

// 	max = fmax(cube->max_width, cube->max_height);
// 	scale = max / 4;
// 	if (scale == 0)
// 		scale = 1;
// 	return (scale);
// }

// int32_t	init_2d_map(t_cube *cube)
// {
// 	int	scale;

// 	scale = calculate_scale(cube);
// 	printf("scale = %d\n", scale);
// 	cube->map->mini_width = cube->max_width / scale;
// 	cube->map->mini_height = cube->max_height / scale;
// 	printf("Minimap Width = %d, Minimap Height = %d\n", cube->map->mini_width, cube->map->mini_height);
// 	cube->map->mini_width = fmax(cube->max_width, MINI_WIDTH);
// 	cube->map->mini_height = fmax(cube->max_height, MINI_HEIGHT);
// 	printf("Minimap Width = %d, Minimap Height = %d\n", cube->map->mini_width, cube->map->mini_height);
// 	cube->mini = mlx_new_image(cube->mlx, cube->map->mini_width, cube->map->mini_height);
// 	if (!cube->mini)
// 	{
// 		mlx_delete_image(cube->mlx, cube->image);
// 		mlx_delete_image(cube->mlx, cube->mini);
// 		mlx_close_window(cube->mlx);
// 		return (EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(cube->mlx, cube->mini, 0, 0) == -1)
// 	{
// 		mlx_close_window(cube->mlx);
// 		return (EXIT_FAILURE);
// 	}
// 	return (EXIT_SUCCESS);
// }
