/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:35:33 by muhakose          #+#    #+#             */
/*   Updated: 2024/04/29 15:21:00 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

void	put_wall(t_cube *cube, t_line line, t_ray ray)
{
	if (ray.ra > PIDIR && ray.ra <= 3 * PIDIR)
		draw_line(cube->image, line, pixel(255, 0, 0, 255));
	else if (ray.ra > 3 * PIDIR && ray.ra <= 5 * PIDIR)
		draw_line(cube->image, line, pixel(255, 0, 0, 255));
	else if (ray.ra > 5 * PIDIR && ray.ra <= 7 * PIDIR)
		draw_line(cube->image, line, pixel(255, 0, 0, 255));
	else
		draw_line(cube->image, line, pixel(255, 0, 0, 255));

}

void	draw_3d(t_cube *cube, t_ray ray, int i)
{
	t_line		line;
	int			dist = 0;
	double		lineO;
	double		lined;

	lined = sqrt(ray.xl * ray.xl + ray.yl * ray.yl);
	if (lined == 0)
		lined = 1;
	dist = 720 * 16 / lined;
	if (dist > 720)
		dist = 720;
	lineO = 350 - (dist / 2);
	int x = -1;
	while (++x < 18)
	{
		line = init_line((18 * i) + x + 5 + 256, lineO,(18 * i) + x + 5 + 256, dist + lineO);
		put_wall(cube, line, ray);
		line = init_line((18 * i) + x + 5 + 256, dist + lineO,(18 * i) + x + 5 + 256, 720);
		draw_line(cube->image, line, cube->details->floor_rgb);
		line = init_line((18 * i) + x + 5 + 256, 0,(18 * i) + x + 5 + 256, lineO);
		draw_line(cube->image, line, cube->details->ceiling_rgb);
	}
}
