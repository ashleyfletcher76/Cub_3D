/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:35:33 by muhakose          #+#    #+#             */
/*   Updated: 2024/04/30 16:25:35 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"


void	put_wall(t_cube *cube, double dist, double lineO, int i)
{
	int j;
	int32_t color;
	u_int8_t *pixels;

	j = 0;
	while (j < dist + lineO)
	{
		pixels = &cube->wall_tex.pixels[j];
		color = pixel(pixels[0], pixels[1], pixels[2], pixels[3]);
		mlx_put_pixel(cube->image, i, j + lineO, color);
		j++;
	}
}


void	draw_3d(t_cube *cube, t_ray ray, int i)
{
	t_line		line;
	double		dist;
	double		lineO;
	double		ca;

	ca = cube->player.pa - ray.ra;
	if (ca < 0)
		ca += 2 * PI;
	else if (ca > 2 * PI)
		ca -= 2 * PI;
	ray.dist = ray.dist * cos(ca);
	if (ray.dist == 0)
		ray.dist = 1;
	dist = HEIGHT * 32 / ray.dist;
	lineO = HEIGHT / 2 - (dist / 2);


	double	ty_step = 32 / dist;
	float	ty_off = 0;
	if (dist > HEIGHT)
	{
		dist = HEIGHT;
		ty_off = (dist - HEIGHT) / 2.0;
	}
	int lineoff = HEIGHT / 2 - (dist / 2);

	u_int8_t *pixels;
	int color;
	double shade = 1;
	int y;
	double ty = ty_off * ty_step;
	double tx;
	if (shade == 1) {tx = (int) (ray.rx / 2.0) % 32; if (ray.ra > PI){tx = 31 - tx;}}
	else 			{tx = (int) (ray.ry / 2.0) % 32; if (ray.ra > PI / 2 && ray.ra < 3 * PI / 2){ tx = 31 - tx;}}

	for (y = 0; y < dist; y++)
	{
		int index = (int) ty * 32 + tx;
		pixels = &cube->wall_tex.pixels[index * 4];
		color = pixel(pixels[0] , pixels[1] , pixels[2], pixels[3]);
		mlx_put_pixel(cube->image, i, y + lineoff, color);
		ty += ty_step;
	}




	line = init_line(i, dist + lineO, i, HEIGHT);
	draw_line(cube->image, line, cube->details->floor_rgb);
	line = init_line(i, 0, i, lineO);
	draw_line(cube->image, line, cube->details->ceiling_rgb);
}
