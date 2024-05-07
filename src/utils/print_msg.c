/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:33:10 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/07 15:59:23 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

void	print_error_exit(int flag)
{
	if (flag == 0)
		ft_putendl_fd("Incorrect arguments.", 2);
	else if (flag == 1)
		ft_putendl_fd("Invalid map.", 2);
	else if (flag == 2)
		ft_putendl_fd("Map creation failed", 2);
	else if (flag == 3)
		ft_putendl_fd("Cube creation failed", 2);
	else if (flag == 4)
		ft_putendl_fd("Structure is NULL", 2);
	else if (flag == 5)
		perror("Failed to open map file");
	else if (flag == 6)
		ft_putendl_fd("You pressed escaped cos your scared", 0);
	exit(EXIT_FAILURE);
}

void	free_print_exit(t_cube *cube, int flag, int i)
{
	if (flag == 0)
	{
		free (cube->map);
		ft_putendl_fd("Map creation failed", 2);
	}
	else if (flag == 1)
	{
		while (--i >= 0)
			free (cube->map->map[i]);
		free (cube->map->map);
		free (cube->map);
		ft_putendl_fd("Map creation failed", 2);
	}
	else if (flag == 2)
	{
		ft_putendl_fd("Invalid map.", 2);
		final_free(cube);
	}
	else if (flag == 3)
	{
		perror("Failed to open map file");
		final_free(cube);
	}
	exit(EXIT_FAILURE);
}

void	free_print_exit_two(t_cube *cube, t_point *stack, int flag)
{
	if (flag == 0)
	{
		ft_putendl_fd("Failed to input line to map data", 2);
		final_free(cube);
	}
	if (flag == 1)
	{
		ft_putendl_fd("Invalid map", 2);
		free (stack);
		final_free(cube);
	}
	if (flag == 2)
	{
		ft_putendl_fd("Invalid map", 2);
		final_free(cube);
	}
	if (flag == 3)
	{
		ft_putendl_fd("Invalid MLX initalization", 2);
		final_free(cube);
	}
	exit(EXIT_FAILURE);
}

void	free_print_exit_three(t_cube *cube, int flag)
{
	if (flag == 0)
	{
		ft_putendl_fd("Failed to open texture", 2);
		final_free(cube);
	}
	exit(EXIT_FAILURE);
}
