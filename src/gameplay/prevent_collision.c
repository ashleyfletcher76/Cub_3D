/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prevent_collision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:05:38 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/06 16:38:37 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

int	is_wall_collision(t_cube *cube, int x, int y)
{
	if (x >= 0 && x < cube->max_width && y >= 0
		&& y < cube->max_height)
		return (cube->map->map[y][x] == '1');
	return (0);
}
