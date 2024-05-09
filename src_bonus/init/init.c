/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:09:58 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/09 13:54:23 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int32_t	init_mlx(t_cube *cube)
{
	cube->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!cube->mlx)
		return (EXIT_FAILURE);
	cube->image = mlx_new_image(cube->mlx, WIDTH * 2, HEIGHT * 2);
	if (!cube->image)
	{
		mlx_delete_image(cube->mlx, cube->image);
		mlx_close_window(cube->mlx);
		free_print_exit_two(cube, NULL, 3);
	}
	if (mlx_image_to_window(cube->mlx, cube->image, 0, 0) == -1)
	{
		mlx_delete_image(cube->mlx, cube->image);
		mlx_close_window(cube->mlx);
		free_print_exit_two(cube, NULL, 3);
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
		cube->map->map[i][cube->max_width] = '\0';
	}
}

static void	init_texture_helper(t_cube *cube)
{
	cube->texture.north = NULL;
	cube->texture.south = NULL;
	cube->texture.east = NULL;
	cube->texture.west = NULL;
	cube->texture.teleport = NULL;
	cube->texture.teleport_tex = NULL;
	cube->texture.door = NULL;
	cube->texture.door_tex = NULL;
	cube->gun.gun = NULL;
	cube->gun.gun_t = NULL;
	cube->gun.gun2 = NULL;
	cube->gun.gun2_t = NULL;
}

void	init_mouse(t_cube *cube)
{
	cube->mouse.x = WIDTH / 2;
	cube->mouse.y = HEIGHT / 2;
}

void	init_cube(t_cube **cube, t_cube temp_cube)
{
	*cube = malloc(sizeof(t_cube));
	if (!*cube)
		print_error_exit(3);
	(*cube)->max_height = temp_cube.max_height;
	(*cube)->max_width = temp_cube.max_width;
	(*cube)->map = NULL;
	(*cube)->details = malloc(sizeof(t_details));
	if (!(*cube)->details)
		print_error_exit(2);
	(*cube)->details->north = NULL;
	(*cube)->details->south = NULL;
	(*cube)->details->east = NULL;
	(*cube)->details->west = NULL;
	(*cube)->details->floor = NULL;
	(*cube)->details->ceiling = NULL;
	(*cube)->details->floor_rgb = 0;
	(*cube)->details->ceiling_rgb = 0;
	(*cube)->details_found = 0;
	init_texture_helper(*cube);
	init_mouse(*cube);
}
