/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:35:33 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/02 10:50:07 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"


void	draw_3d(t_cube *cube, t_ray ray, int i)
{
	t_line		line;
	int			dist;
	double		lineO;
	int			ca;

	ca = fixang(cube->player.pa - ray.ra);
	ray.dist = ray.dist * cos(degtorad(ca));
	if (ray.dist == 0)
		ray.dist = 1;
	dist = HEIGHT * 32 / ray.dist;
	double	ty_step = cube->wall_tex.height / dist;
	double	ty_off = 0;
	lineO = HEIGHT / 2 - (dist / 2);


	if (dist > HEIGHT)
	{
		dist = HEIGHT;
		ty_off = (dist - HEIGHT) / 2.0;
	}
	int lineoff = HEIGHT / 2 - (dist / 2);

	u_int8_t *pixels;
	int color;
	int y;
	double ty = ty_off * ty_step;
	double tx;

	tx = ((int)(ray.rx / 2.0) % 80);

	for (y = 0; y < dist; y++)
	{
		int index = ((int)tx * cube->wall_tex.width + (int)ty) * 4;
		pixels = &cube->wall_tex.pixels[index];
		color = pixel(pixels[0]  , pixels[1]  , pixels[2] , pixels[3]);
		mlx_put_pixel(cube->image, i, y + lineoff, color);
		ty += ty_step;
	}




	line = init_line(i, dist + lineoff, i, HEIGHT);
	draw_line(cube->image, line, cube->details->floor_rgb);
	line = init_line(i, 0, i, lineoff);
	draw_line(cube->image, line, cube->details->ceiling_rgb);
}
