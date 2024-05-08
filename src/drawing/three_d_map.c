/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:35:33 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/08 15:15:23 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_textures(t_cube *cube, t_ray ray, int i, mlx_texture_t tex)
{
	double		ty;
	double		tx;
	u_int8_t	*pixels;
	int			index;
	int			y;

	y = 0;
	ty = ray.ty_off * ray.ty_step;
	if (ray.shade == 1)
		tx = ((ray.rx) - (int)ray.rx) * tex.width;
	else
		tx = (ray.ry - (int)ray.ry) * tex.width;
	while (y < ray.dist)
	{
		index = ((int)tx * tex.height + (int)ty) * 4;
		pixels = &tex.pixels[index];
		mlx_put_pixel(cube->image, i, y + ray.lineoff,
			pixel(pixels[0], pixels[1], pixels[2], pixels[3]));
		ty += ray.ty_step;
		y++;
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

mlx_texture_t	find_facing(t_cube *cube, t_ray ray)
{
	mlx_texture_t	tex;

	if (ray.shade == 1)
	{
		if (ray.ra > 180)
			tex = cube->texture.south_tex;
		else
			tex = cube->texture.north_tex;
	}
	else
	{
		if (ray.ra > 90 && ray.ra < 270)
			tex = cube->texture.west_tex;
		else
			tex = cube->texture.east_tex;
	}
	return (tex);
}

void	draw_3d(t_cube *cube, t_ray ray, int i)
{
	int				ca;
	mlx_texture_t	tex;

	tex = find_facing(cube, ray);
	ca = fixang(cube->player.pa - ray.ra);
	ray.disth = ray.disth * cos(degtorad(ca));
	ray.dist = (HEIGHT) / ray.disth;
	ray.ty_step = tex.height / (double)ray.dist;
	ray.ty_off = 0;
	if (ray.dist > HEIGHT)
	{
		ray.ty_off = (ray.dist - HEIGHT) / 2.0;
		ray.dist = HEIGHT;
	}
	ray.lineoff = HEIGHT / 2 - (ray.dist / 2);
	draw_floor_ceiling(cube, ray, i);
	draw_textures(cube, ray, i, tex);
}
