/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:35:33 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/09 17:16:01 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
		index = ((int)ty * tex.height + (int)tx) * 4;
		pixels = &tex.pixels[index];
		if (pixels[0] != 0 && pixels[1] != 0 && pixels[2] != 0)
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
		if (cube->map->map[(int)ray.ry][(int)ray.rx] == 'Z')
			return (*cube->texture.teleport_tex);
		if (ray.ra > 180)
			tex = cube->texture.south_tex;
		else
			tex = cube->texture.north_tex;
	}
	else
	{
		if (cube->map->map[(int)ray.ry][(int)ray.rx] == 'Z')
			return (*cube->texture.teleport_tex);
		if (ray.ra > 90 && ray.ra < 270)
			tex = cube->texture.west_tex;
		else
			tex = cube->texture.east_tex;
	}
	return (tex);
}


mlx_texture_t	find_door_dist(t_cube *cube, t_ray ray)
{
	mlx_texture_t tex;

	if (ray.distdv < 2)
		tex = cube->texture.door_open_tex;
	else
		tex = cube->texture.door_close_tex;
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
	ray.ty_step = tex.width / (double)ray.dist;
	ray.ty_off = 0;
	if (ray.dist > HEIGHT)
	{
		ray.ty_off = (ray.dist - HEIGHT) / 2.0;
		ray.dist = HEIGHT;
	}
	ray.lineoff = HEIGHT / 2 - (ray.dist / 2);
	draw_textures(cube, ray, i, tex);
}

void	draw_3d(t_cube *cube, t_ray ray, int i)
{
	int				ca;
	mlx_texture_t	tex;

	tex = find_facing(cube, ray);
	ca = fixang(cube->player.pa - ray.ra);
	ray.distv = ray.distv * cos(degtorad(ca));
	ray.dist = (HEIGHT) / ray.distv;
	ray.ty_step = tex.width / (double)ray.dist;
	ray.ty_off = 0;
	if (ray.dist > HEIGHT)
	{
		ray.ty_off = (ray.dist - HEIGHT) / 2.0;
		ray.dist = HEIGHT;
	}
	ray.lineoff = HEIGHT / 2 - (ray.dist / 2);
	draw_floor_ceiling(cube, ray, i);
	draw_textures(cube, ray, i, tex);
	if (ray.distv > ray.distdv)
		draw_door(cube, ray, i);
}
