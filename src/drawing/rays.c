/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:53:18 by muhakose          #+#    #+#             */
/*   Updated: 2024/04/26 14:47:29 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

t_ray	init_ray(float pa, float px, float py)
{
	t_ray	ray;

	ray.rx = px;
	ray.ry = py;
	ray.xo = 0;
	ray.yo = 0;
	ray.l = 0;
	ray.ra = pa - (DR * FPOV / 2);
	ray.mx = ray.rx / MAPSIZE;
	ray.my = ray.ry / MAPSIZE;
	return (ray);
}

void	set_ray(t_ray *ray, float px, float py)
{
	ray->rx = px;
	ray->ry = py;
	ray->mx = ray->rx / MAPSIZE;
	ray->my = ray->ry / MAPSIZE;
	ray->xo = cos(ray->ra);
	ray->yo = sin(ray->ra);
	ray->l = 0;
}

int	is_done(t_cube *cube, int x, int y)
{
	if (x < 0 || x >= cube->max_width)
		return (false);
	if (y < 0 || y >= cube->max_height)
		return (false);
	if (cube->map->map[y][x] == '1')
		return (false);
	return (true);
}

void	draw_3d(t_cube *cube, t_ray ray)
{
	t_line	line;
	float	dist = 0;

	dist = HEIGHT * 32 / ray.l;
	line = init_line(ray.rx * 5 + 530, HEIGHT / 2, ray.rx + 530, ray.rx * 5 + 530 + dist);
	draw_line(cube->image, line, pixel(255, 0, 0, 255));
}

void	draw_ray(t_cube *cube)
{
	t_ray	ray;
	t_line	line;
	int		i;

	i = -1;
	ray = init_ray(cube->player.pa, cube->player.px, cube->player.py);
	while (++i < FPOV)
	{
		set_ray(&ray, cube->player.px, cube->player.py);
		while (is_done(cube, ray.mx, ray.my))
		{
			ray.mx = (int)(ray.rx) / MAPSIZE;
			ray.my = (int)(ray.ry) / MAPSIZE;
			ray.rx += ray.xo;
			ray.ry += ray.yo;
			if (ray.yo < 0)
				ray.l -= ray.yo;
			else	
				ray.l += ray.yo;
		}
		line = init_line(cube->player.px, cube->player.py, ray.rx, ray.ry);
		draw_line(cube->image, line, pixel(0, 0, 255, 255));
		//draw_3d(cube, ray);
		ray.ra += DR;
	}
}

