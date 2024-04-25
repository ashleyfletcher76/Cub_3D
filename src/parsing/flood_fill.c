/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:28:27 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/25 14:41:55 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

void	flood_fill(char **map, t_cube *cube, int x, int y)
{
	t_point	*stack;
	t_point	point;
	int		top;

	stack = malloc(cube->max_width * cube->max_height * sizeof(t_point));
	if (!stack)
		free_print_exit_two(cube, 1);
	top = 0;
	stack[top++] = (t_point){x, y};
	while (top > 0)
	{
		point = stack[--top];
		if (point.x < 0 || point.y < 0 || point.x >= cube->max_width
			|| point.y >= cube->max_height)
		{
			free (stack);
			free_print_exit_two(cube, 0);
		}
		if (map[point.y][point.x] == '1' || map[point.y][point.x] == 'V')
			continue ;
		if (map[point.y][point.x] == '0')
			map[point.y][point.x] = 'V';
		 if (point.x + 1 < cube->max_width && map[point.y][point.x + 1] == '0')
			stack[top++] = (t_point){point.x + 1, point.y};
		if (point.x > 0 && map[point.y][point.x - 1] == '0')
			stack[top++] = (t_point){point.x - 1, point.y};
		if (point.y + 1 < cube->max_height && map[point.y + 1][point.x] == '0')
			stack[top++] = (t_point){point.x, point.y + 1};
		if (point.y > 0 && map[point.y - 1][point.x] == '0')
			stack[top++] = (t_point){point.x, point.y - 1};
	}
	free (stack);
}

// void	flood_fill(char **map, t_cube *cube, int x, int y)
// {
// 	if (x < 0 || y < 0)
// 	{
// 		printf("Fill 1\n");
// 		free_print_exit(cube, 2, 0);
// 	}
// 	if (x >= cube->max_width || y >= cube->max_height)
// 	{
// 		printf("Fill 2\n");
// 		free_print_exit(cube, 2, 0);
// 	}
// 	if (map[y][x] == '1' || map[y][x] == 'V')
// 		return ;
// 	map[y][x] = 'V';
// 	flood_fill(map, cube, x + 1, y);
// 	flood_fill(map, cube, x - 1, y);
// 	flood_fill(map, cube, x, y + 1);
// 	flood_fill(map, cube, x, y - 1);
// }
