/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prevent_collision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:05:38 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/07 17:59:14 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall_collision(t_cube *cube, int x, int y)
{
	if (x >= 0 && x < cube->max_width && y >= 0
		&& y < cube->max_height)
		return (cube->map->map[y][x] == '1');
	return (0);
}
