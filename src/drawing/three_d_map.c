/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:35:33 by muhakose          #+#    #+#             */
/*   Updated: 2024/04/29 16:01:26 by muhakose         ###   ########.fr       */
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
	double		dist = 0;
	double		lineO;
	double		lined;
	double		ca = cube->player.pa - ray.ra;
	if (ca < 0)
		ca += 2 * PI;
	else if (ca > 2 * PI)
		ca -= 2 * PI;
	
	lined = sqrt(ray.xl * ray.xl + ray.yl * ray.yl);
	lined = lined * cos(ca);

	if (lined == 0)
		lined = 1;
	dist = 720 * 48 / lined;
	if (dist > 720)
		dist = 720;
	lineO = 360 - (dist / 2);
	int x = -1;

		line = init_line((WIDTH / (FPOV * 18) * i) + x + 5 + 256, lineO,(WIDTH / (FPOV * 18) * i) + x + 5 + 256, dist + lineO);
		put_wall(cube, line, ray);
		line = init_line((WIDTH / (FPOV * 18) * i) + x + 5 + 256, dist + lineO,(WIDTH / (FPOV * 18) * i) + x + 5 + 256, 720);
		draw_line(cube->image, line, cube->details->floor_rgb);
		line = init_line((WIDTH / (FPOV * 18) * i) + x + 5 + 256, 0,(WIDTH / (FPOV * 18) * i) + x + 5 + 256, lineO);
		draw_line(cube->image, line, cube->details->ceiling_rgb);
}
