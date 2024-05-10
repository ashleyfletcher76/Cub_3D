/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:22:12 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/10 15:54:00 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_door_textures(t_cube *cube, t_ray ray, int i, mlx_texture_t tex)
{
	double		ty;
	double		tx;
	u_int8_t	*pixels;
	int			index;
	int			y;

	y = 0;
	ty = ray.ty_off * ray.ty_step;
	if (ray.door_shade == 1)
		tx = ((ray.dvx) - (int)ray.dvx) * tex.width;
	else
		tx = (ray.dhy - (int)ray.dhy) * tex.width;
	while (y < ray.dist)
	{
		index = ((int)ty * tex.width + (int)tx) * 4;
		pixels = &tex.pixels[index];
		if (pixels[0] != 0 && pixels[1] != 0 && pixels[2] != 0
			&& pixels[3] != 0)
			mlx_put_pixel(cube->image, i, y + ray.lineoff,
				pixel(pixels[0], pixels[1], pixels[2],
					pixels[3] * cube->pause));
		ty += ray.ty_step;
		y++;
	}
}

mlx_texture_t	find_door_dist(t_cube *cube, t_ray ray)
{
	mlx_texture_t	tex;

	if (ray.distdv > 2)
		tex = cube->texture.door_close_tex;
	else if (ray.distdv > 1)
		tex = cube->texture.door_half_tex;
	else
		tex = cube->texture.door_open_tex;
	return (tex);
}

void	draw_door(t_cube *cube, t_ray ray, int i)
{
	int				ca;
	mlx_texture_t	tex;

	tex = find_door_dist(cube, ray);
	ca = fixang(cube->player.pa - ray.ra);
	ray.distdv = ray.distdv * cos(degtorad(ca));
	ray.dist = (HEIGHT) / ray.distdv;
	ray.ty_step = tex.height / (double)ray.dist;
	ray.ty_off = 0;
	if (ray.dist > HEIGHT)
	{
		ray.ty_off = (ray.dist - HEIGHT) / 2.0;
		ray.dist = HEIGHT;
	}
	ray.lineoff = HEIGHT / 2 - (ray.dist / 2);
	draw_door_textures(cube, ray, i, tex);
}
