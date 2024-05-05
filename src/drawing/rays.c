/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:53:18 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/03 15:56:32 by asfletch         ###   ########.fr       */
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
	ray.ra = fixang(player.pa);
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


void	find_dist(t_ray *ray, t_player player)
{
	double x;
	double y;

	x = ray->rx - player.px;
	y = ray->ry - player.py;
	ray->dist = sqrt(x * x + y * y);
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
	while (i < 1)
	{
		dof = 0;
		if (ray.ra != 180 || ray.ra != 90)
			aTan = tan(degtorad(ray.ra));
		if (cos(degtorad(ray.ra) > 0.001)) // loking left
		{
			ray.rx = (((int)cube->player.px >> 6 ) << 6) + MAPSIZE;
			ray.ry = (cube->player.px - ray.rx) * aTan + cube->player.py;
			ray.xo = 64;
			ray.xo = ray.xo * aTan;
		}
		else if (cos(degtorad(ray.ra) < -0.001))
		{
			ray.rx = (((int)cube->player.px >> 6 ) << 6) - 0.0001;
			ray.ry = (cube->player.px - ray.rx) * aTan + cube->player.py;
			ray.xo = -MAPSIZE;
			ray.xo = ray.xo * aTan;
		}
		else
		{
			ray.rx = cube->player.px * MAPSIZE;
			ray.ry = cube->player.py * MAPSIZE;
			dof = 8;
		}
		while (dof < 8)
		{
			ray.mx = (int)ray.rx >> 6;
			ray.my = (int)ray.ry >> 6;
			if (is_done(cube, ray.mx, ray.my))
				dof = 8;
			else
			{
				ray.rx += ray.xo;
				ray.ry += ray.yo;
				dof += 1;
			}
		}
		line = init_line(cube->player.px * MAPSIZE, cube->player.py * MAPSIZE, ray.rx, ray.ry);
		draw_line(cube->image, line, pixel(255, 0, 0, 255));
		i++;
	}
}
