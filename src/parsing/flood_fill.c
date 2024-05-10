/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:28:27 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/09 12:48:20 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	get_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

static void	fill_helper(t_cube *cube, t_point *stack, t_point point)
{
	if (point.x <= 0 || point.y <= 0 || point.x >= cube->max_width - 1
		|| point.y >= cube->max_height - 1)
	{
		printf("Flood exit\n");
		free_print_exit_two(cube, stack, 1);
	}
}

static void	move_point_y(t_cube *cube, t_point *stack, t_point point, int *top)
{
	if (point.y + 1 < cube->max_height
		&& cube->map->map[point.y + 1][point.x] != '1'
			&& cube->map->map[point.y + 1][point.x] != 'V')
	{
		stack[*top] = get_point(point.x, point.y + 1);
		(*top)++;
	}
	if (point.y > 0 && cube->map->map[point.y - 1][point.x] != '1'
		&& cube->map->map[point.y - 1][point.x] != 'V')
	{
		stack[*top] = get_point(point.x, point.y - 1);
		(*top)++;
	}
}

static void	move_point_x(t_cube *cube, t_point *stack, t_point point, int *top)
{
	if (point.x + 1 < cube->max_width
		&& cube->map->map[point.y][point.x + 1] != '1'
			&& cube->map->map[point.y][point.x + 1] != 'V')
	{
		stack[*top] = get_point(point.x + 1, point.y);
		(*top)++;
	}
	if (point.x > 0 && cube->map->map[point.y][point.x - 1] != '1'
		&& cube->map->map[point.y][point.x - 1] != 'V')
	{
		stack[*top] = get_point(point.x - 1, point.y);
		(*top)++;
	}
}

void	flood_fill(t_cube *cube, int x, int y)
{
	t_point	*stack;
	t_point	point;
	int		top;

	stack = malloc((cube->max_width + 1)
			* (cube->max_height + 1) * sizeof(t_point));
	if (!stack)
		free_print_exit(cube, 2, 0);
	top = 0;
	stack[top++] = get_point(x, y);
	while (top > 0)
	{
		point = stack[--top];
		fill_helper(cube, stack, point);
		if (cube->map->map[point.y][point.x] == '1'
			|| cube->map->map[point.y][point.x] == 'V')
			continue ;
		cube->map->map[point.y][point.x] = 'V';
		move_point_x(cube, stack, point, &top);
		move_point_y(cube, stack, point, &top);
	}
	free (stack);
}
