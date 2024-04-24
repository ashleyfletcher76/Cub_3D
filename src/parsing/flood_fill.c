/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:28:27 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/24 18:40:33 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

void	fill(char **tab, t_cube *cube, t_point curr, char to_fill)
{
	if (curr.x < 0 || curr.y < 0 || curr.x  >= cube->max_width || curr.y >= cube->max_height
	|| tab[curr.y][curr.x] != to_fill)
		return ;

	tab[curr.y][curr.x] = '1';
	fill(tab, cube, (t_point){curr.x + 1, curr.y}, to_fill);
	fill(tab, cube, (t_point){curr.x - 1, curr.y}, to_fill);
	fill(tab, cube, (t_point){curr.x, curr.y + 1}, to_fill);
	fill(tab, cube, (t_point){curr.x, curr.y - 1}, to_fill);
}

void	flood_fill(char **tab, t_cube *cube, t_point begin)
{
	fill(tab, cube, begin, ' ');
}
