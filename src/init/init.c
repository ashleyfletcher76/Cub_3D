/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:09:58 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/23 17:44:36 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

int32_t	init_mlx(t_cube *cube)
{
	cube->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!cube->mlx)
		return (EXIT_FAILURE);
	cube->image = mlx_new_image(cube->mlx, cube->max_width
			* cube->map_size, cube->max_height * cube->map_size);
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

void	init_map(t_cube *cube)
{
	int	i;

	if (!cube)
		print_error_exit(4);
	if (!cube->map)
	{
		cube->map = ft_calloc(1, sizeof(t_map));
		if (!cube->map)
			print_error_exit(2);
	}
	if (!cube->map->map)
	{
		cube->map->map = malloc(cube->max_height * sizeof(char *));
		if (!cube->map->map)
			free_print_exit(cube, 0, 0);
	}
	i = -1;
	while (++i < cube->max_height)
	{
		cube->map->map[i] = ft_calloc(cube->max_width + 1, sizeof(char));
		if (!cube->map->map[i])
			free_print_exit(cube, 1, i);
	}
	cube->map->grid_size = cube->max_width * cube->max_height;
}

void	init_cube(t_cube **cube, t_cube *temp_cube)
{
	*cube = malloc(sizeof(t_cube));
	if (!*cube)
		print_error_exit(3);
	(*cube)->max_height = temp_cube->max_height;
	(*cube)->max_width = temp_cube->max_width;
	(*cube)->width_nospace = temp_cube->width_nospace;
	(*cube)->map_size = 16;
	(*cube)->map = NULL;
}
