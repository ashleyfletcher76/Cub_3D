/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:41:28 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/20 13:53:33 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

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
