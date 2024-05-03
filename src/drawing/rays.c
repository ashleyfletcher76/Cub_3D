/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:53:18 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/03 17:42:19 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

t_ray	init_ray(t_player player)
{
	t_ray	ray;

	ray.rx = player.px;
	ray.ry = player.py;
	ray.xo = 0;
	ray.yo = 0;
	ray.vx = 0;
	ray.vy = 0;
	ray.disth = 0;
	ray.distv = 0;
	ray.dist = 0;
	ray.ra = fixang(player.pa - FPOV / 2);
	ray.mx = (int)ray.rx;
	ray.my = (int)ray.ry;
	return (ray);
}

void	set_ray(t_ray *ray, double px, double py)
{
	ray->rx = px;
	ray->ry = py;
	ray->mx = (int)ray->rx;
	ray->my = ray->ry;
	ray->dist = 0;
	ray->disth = 0;
	ray->distv = 0;
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


double	find_dist(t_ray *ray, t_player player)
{
	double x;
	double y;

	x = ray->rx - player.px;
	y = ray->ry - player.py;
	return (sqrt(x * x + y * y));
}

void	draw_ray(t_cube *cube)
{
	t_ray	ray;
	t_line	line;
	int		i;
	int		dof;
	float	aTan;

	i = 0;
	ray = init_ray(cube->player);
	while (i < WIDTH)
	{
		dof = 0;
		aTan = tan(degtorad(ray.ra));
		if (cos(degtorad(ray.ra)) > 0.001) // looking right
		{
			ray.rx =((int)cube->player.px) + 1;
			ray.ry =(cube->player.px - ray.rx) * aTan + cube->player.py;
			ray.xo = 1;
			ray.yo = -ray.xo * aTan;
		}
		else if (cos(degtorad(ray.ra)) < -0.001) // looking left
		{
			ray.rx = ((int)cube->player.px) - 0.0001;
			ray.ry = (cube->player.px - ray.rx) * aTan + cube->player.py ;
			ray.xo = -1;
			ray.yo = -ray.xo * aTan;
		}
		else
		{
			ray.rx = cube->player.px;
			ray.ry = cube->player.py;
			if (sin(degtorad(ray.ra)) > 0)
				ray.yo = -1;
			else
				ray.yo = 1;
			ray.xo = 0;
		}
		while (dof != -1)
		{
			ray.mx = (int)ray.rx;
			ray.my = (int)ray.ry;
			if (!is_done(cube, ray.mx, ray.my))
			{
				ray.distv = find_dist(&ray, cube->player);
				break ;
			}
			else
			{
				ray.rx += ray.xo;
				ray.ry += ray.yo;
			}
		}
		double vx = ray.rx;
		double vy = ray.ry;
		dof = 0;
		aTan = 1.0/aTan;
		if (sin(degtorad(ray.ra)) > 0.001) // looking up
		{
			ray.ry =((int)cube->player.py) - 0.0001;
			ray.rx =(cube->player.py - ray.ry) * aTan + cube->player.px;
			ray.yo = -1;
			ray.xo = -ray.yo * aTan;
		}
		else if (sin(degtorad(ray.ra)) < -0.001) // looking down
		{
			ray.ry = ((int)cube->player.py) + 1;
			ray.rx = (cube->player.py - ray.ry) * aTan + cube->player.px;
			ray.yo = 1;
			ray.xo = -ray.yo * aTan;
		}
		else
		{
			ray.rx = cube->player.px;
			ray.ry = cube->player.py;
			if (cos(degtorad(ray.ra)) > 0)
				ray.xo = 1;
			else
				ray.xo = -1;
			ray.yo = 0;
		}
		while (dof != -1)
		{
			ray.mx = (int)ray.rx;
			ray.my = (int)ray.ry;
			if (!is_done(cube, ray.mx, ray.my))
			{
				ray.disth = find_dist(&ray, cube->player);
				break ;
			}
			else
			{
				ray.rx += ray.xo;
				ray.ry += ray.yo;
			}
		}
		if (ray.distv < ray.disth)
		{
			ray.rx = vx;
			ray.ry = vy;
			ray.disth = ray.distv;
		}
		draw_3d(cube, ray, i);
		line = init_line(cube->player.px * MAPSIZE, cube->player.py * MAPSIZE, ray.rx * MAPSIZE, ray.ry * MAPSIZE);
		draw_line(cube->image, line, pixel(255, 0, 0, 255));
		ray.ra = fixang(ray.ra + DR);
		i++;
	}
}
