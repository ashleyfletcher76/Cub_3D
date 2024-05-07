/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:41:28 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/07 18:01:12 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_cube *cube)
{
	int	y;
	int	x;

	y = -1;
	while (++y < cube->max_height)
	{
		x = -1;
		while (++x < cube->max_width)
			printf("%c ", cube->map->map[y][x]);
		printf("\n");
	}
}
