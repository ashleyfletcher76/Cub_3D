/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:28:27 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/26 12:31:25 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

static t_point	get_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

static void	move_point_y(t_cube *cube, t_point *stack, t_point point, int *top)
{
	if (point.y + 1 < cube->max_height)
	{
		stack[*top] = get_point(point.x, point.y + 1);
		(*top)++;
	}
	else
		free_print_exit_two(cube, stack, 1);
	if (point.y > 0)
	{
		stack[*top] = get_point(point.x, point.y - 1);
		(*top)++;
	}
	else
		free_print_exit_two(cube, stack, 1);
}

static void	move_point_x(t_cube *cube, t_point *stack, t_point point, int *top)
{
	if (point.x + 1 < cube->max_width)
	{
		stack[*top] = get_point(point.x + 1, point.y);
		(*top)++;
	}
	else
		free_print_exit_two(cube, stack, 1);
	if (point.x > 0)
	{
		stack[*top] = get_point(point.x - 1, point.y);
		(*top)++;
	}
	else
		free_print_exit_two(cube, stack, 1);
}

static void	fill_helper(t_cube *cube, t_point *stack, t_point point)
{
	if (point.x < 0 || point.y < 0 || point.x >= cube->max_width
		|| point.y >= cube->max_height)
		free_print_exit_two(cube, stack, 1);
}

void	flood_fill(t_cube *cube, int x, int y)
{
	t_point	*stack;
	t_point	point;
	int		top;

	stack = malloc(cube->max_width + 1 * cube->max_height + 1 * sizeof(t_point));
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
