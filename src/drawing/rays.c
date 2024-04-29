/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:53:18 by muhakose          #+#    #+#             */
/*   Updated: 2024/04/29 15:11:26 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

t_ray	init_ray(double pa, double px, double py)
{
	t_ray	ray;

	ray.rx = px;
	ray.ry = py;
	ray.xo = 0;
	ray.yo = 0;
	ray.xl = 0;
	ray.yl = 0;
	ray.ra = pa - (DR * FPOV / 2);
	ray.mx = ray.rx / MAPSIZE;
	ray.my = ray.ry / MAPSIZE;
	return (ray);
}

void	set_ray(t_ray *ray, double px, double py)
{
	ray->rx = px;
	ray->ry = py;
	ray->mx = ray->rx / MAPSIZE;
	ray->my = ray->ry / MAPSIZE;
	ray->xo = cos(ray->ra);
	ray->yo = sin(ray->ra);
	ray->xl = 0;
	ray->yl = 0;
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


void	find_dist(t_ray *ray)
{
	if (ray->yo < 0)
		ray->yl -= ray->yo;
	else
		ray->yl += ray->yo;
	if (ray->xo < 0)
		ray->xl -= ray->xo;
	else
		ray->xl += ray->xo;
}

void	draw_ray(t_cube *cube)
{
	t_ray	ray;
	t_line	line;
	int		i;

	i = -1;
	ray = init_ray(cube->player.pa, cube->player.px, cube->player.py);
	while (++i < FPOV * 2)
	{
		set_ray(&ray, cube->player.px, cube->player.py);
		while (is_done(cube, ray.mx, ray.my))
		{
			ray.mx = (int)(ray.rx) / MAPSIZE;
			ray.my = (int)(ray.ry) / MAPSIZE;
			ray.rx += ray.xo;
			ray.ry += ray.yo;
			find_dist(&ray);
		}
		line = init_line(cube->player.px, cube->player.py, ray.rx, ray.ry);
		draw_line(cube->image, line, pixel(0, 255, 0, 255));
		draw_3d(cube, ray, i);
		ray.ra += DR;
	}
}
