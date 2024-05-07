/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:53:18 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/07 18:03:26 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	dda(t_cube *cube, t_ray *ray)
{
	while (1)
	{
		ray->mx = (int)ray->rx;
		ray->my = (int)ray->ry;
		if (!is_done_bonus(cube, ray, ray->mx, ray->my))
		{
			ray->disth = find_dist(ray, cube->player);
			break ;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
		}
	}
}

void	draw_horizontal(t_cube *cube, t_ray *ray, double tanv)
{
	if (cos(degtorad(ray->ra)) > 0.001)
	{
		ray->rx = ((int)cube->player.px) + 1;
		ray->ry = (cube->player.px - ray->rx) * tanv + cube->player.py;
		ray->xo = 1;
		ray->yo = -ray->xo * tanv;
	}
	else if (cos(degtorad(ray->ra)) < -0.001)
	{
		ray->rx = ((int)cube->player.px) - 0.0001;
		ray->ry = (cube->player.px - ray->rx) * tanv + cube->player.py;
		ray->xo = -1;
		ray->yo = -ray->xo * tanv;
	}
	else
	{
		ray->rx = cube->player.px;
		ray->ry = cube->player.py;
		if (sin(degtorad(ray->ra)) > 0)
			ray->yo = -1;
		else
			ray->yo = 1;
		ray->xo = 0;
	}
}

void	draw_vertical(t_cube *cube, t_ray *ray, double tanv)
{
	if (sin(degtorad(ray->ra)) > 0.001)
	{
		ray->ry = ((int)cube->player.py) - 0.0001;
		ray->rx = (cube->player.py - ray->ry) * tanv + cube->player.px;
		ray->yo = -1;
		ray->xo = -ray->yo * tanv;
	}
	else if (sin(degtorad(ray->ra)) < -0.001)
	{
		ray->ry = ((int)cube->player.py) + 1;
		ray->rx = (cube->player.py - ray->ry) * tanv + cube->player.px;
		ray->yo = 1;
		ray->xo = -ray->yo * tanv;
	}
	else
	{
		ray->rx = cube->player.px;
		ray->ry = cube->player.py;
		if (cos(degtorad(ray->ra)) > 0)
			ray->xo = 1;
		else
			ray->xo = -1;
		ray->yo = 0;
	}
}

void	draw_ray(t_cube *cube)
{
	t_ray	ray;
	int		i;

	i = -1;
	ray = init_ray(cube->player);
	while (++i < WIDTH)
	{
		ray.shade = 1;
		ray.tex = '.';
		draw_horizontal(cube, &ray, tan(degtorad(ray.ra)));
		dda(cube, &ray);
		ray.vx = ray.rx;
		ray.vy = ray.ry;
		ray.distv = ray.disth;
		draw_vertical(cube, &ray, 1.0 / tan(degtorad(ray.ra)));
		dda(cube, &ray);
		if (ray.distv < ray.disth)
		{
			ray.rx = ray.vx;
			ray.ry = ray.vy;
			ray.disth = ray.distv;
			ray.shade = 0.5;
		}
		draw_3d(cube, ray, i);
		ray.ra = fixang(ray.ra + (double)FPOV / (double)WIDTH);
	}
}
