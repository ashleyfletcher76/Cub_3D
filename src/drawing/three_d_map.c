/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:35:33 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/05 17:49:51 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

void draw_textures(t_cube *cube, t_ray ray, int i, mlx_texture_t tex)
{
	int y;
	double	ty;
	double	tx;
	int32_t color;
	u_int8_t *pixels;
	int index;

	ty = ray.ty_off * ray.ty_step;
	if (ray.shade == 1)
	{
		tx = (int)(ray.rx) % 80;
	}
	else
	{
		tx = (int)(ray.ry) % 80;
	}



	for (y = 0; y < ray.dist; y++)
	{
		index = ((int)tx * tex.height + (int)ty) * 4;
		pixels = &tex.pixels[index];
		color = pixel(pixels[0], pixels[1] ,pixels[2], pixels[3]);
		mlx_put_pixel(cube->image, i, y + ray.lineoff, color);
		ty += ray.ty_step;
	}
}


void	draw_floor_ceiling(t_cube *cube, t_ray ray, int i)
{
	t_line	line;

	line = init_line(i, ray.dist + ray.lineoff, i, HEIGHT);
	draw_line(cube->image, line, cube->details->floor_rgb);
	line = init_line(i, 0, i, ray.lineoff);
	draw_line(cube->image, line, cube->details->ceiling_rgb);
}

void	draw_3d(t_cube *cube, t_ray ray, int i)
{
	int			ca;

	ca = fixang(cube->player.pa - ray.ra);
	ray.disth = ray.disth * cos(degtorad(ca));
	ray.dist = (HEIGHT) / ray.disth;
	ray.ty_step = cube->texture.north_tex.height / (double)ray.dist;
	ray.ty_off = 0;
	if (ray.dist > HEIGHT)
	{
		ray.ty_off = (ray.dist - 720) / 2.0;
		ray.dist = HEIGHT;
	}
	ray.lineoff = HEIGHT / 2 - (ray.dist / 2);
	draw_textures(cube, ray, i, cube->texture.north_tex);
	draw_floor_ceiling(cube, ray, i);
}

