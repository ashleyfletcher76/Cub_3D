/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:35:33 by muhakose          #+#    #+#             */
/*   Updated: 2024/04/28 14:57:48 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

void	put_wall(t_cube *cube, t_line line, t_ray ray)
{
	printf("ra = %f\n", ray.ra);
	if (ray.ra > PIDIR && ray.ra <= 3 * PIDIR)
		draw_line(cube->image, line, pixel(255, 0, 255, 255));
	else if (ray.ra > 3 * PIDIR && ray.ra <= 5 * PIDIR)
		draw_line(cube->image, line, pixel(255, 0, 255, 255));
	else if (ray.ra > 5 * PIDIR && ray.ra <= 7 * PIDIR)
		draw_line(cube->image, line, pixel(255, 0, 255, 255));
	else
		draw_line(cube->image, line, pixel(255, 0, 255, 255));

}

void	draw_3d(t_cube *cube, t_ray ray, int i)
{
	t_line	line;
	int		dist = 0;
	float	lineO;
	int		lined;

	if (ray.xl > ray.yl)
		lined = (int)ray.xl;
	else
		lined = (int)ray.yl;

	if (lined == 0)
		lined = 1;
	dist = 720 * MAPSIZE / lined;
	if (dist > 720)
		dist = 720;
	lineO = 360 - (dist / 2);
	int x = -1;
	while (++x < 15)
	{
		line = init_line((15 * i) + x + 5, lineO,(15 * i) + x + 5, dist + lineO);
		printf("% i = d\n", i);
		put_wall(cube, line, ray);
	}
}
