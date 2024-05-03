/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:35:33 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/03 17:17:57 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"


void	draw_3d(t_cube *cube, t_ray ray, int i)
{
	t_line		line;
	int			dist;
	double		lineoff;
	int			ca;

	ca = fixang(cube->player.pa - ray.ra);
	ray.disth = ray.disth * cos(degtorad(ca));
	if (ray.disth == 0)
		ray.disth = 0;
	dist = (HEIGHT) / ray.disth;
	if (dist > HEIGHT)
		dist = HEIGHT;
	lineoff = HEIGHT / 2 - (dist / 2);
	line = init_line(i, lineoff, i, dist + lineoff);
	draw_line(cube->image, line, pixel(0,255,0,255));
	line = init_line(i, dist + lineoff, i, HEIGHT);
	draw_line(cube->image, line, cube->details->floor_rgb);
	line = init_line(i, 0, i, lineoff);
	draw_line(cube->image, line, cube->details->ceiling_rgb);
}
