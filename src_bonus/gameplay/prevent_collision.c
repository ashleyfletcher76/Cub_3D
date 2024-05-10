/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prevent_collision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:05:38 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/10 15:36:32 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	is_wall_collision(t_cube *cube, int x, int y)
{
	if (x >= 0 && x < cube->max_width && y >= 0
		&& y < cube->max_height)
	{
		if (cube->map->map[y][x] != 'V' && cube->map->map[y][x] != 'L')
			return (1);
		if (cube->map->map[y][x] == 'Z')
			free_print_exit_three(cube, 1);
	}
	return (0);
}
