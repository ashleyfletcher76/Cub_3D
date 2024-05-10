/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:53:18 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/10 17:19:08 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	dda_h(t_cube *cube, t_ray *ray)
{
	if (ray->flag == 1)
		return ;
	while (1)
	{
		if (!is_done_bonus_h(cube, ray, (int)ray->rx, (int)ray->ry))
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

void	dda_v(t_cube *cube, t_ray *ray)
{
	if (ray->flag == 1)
		return ;
	while (1)
	{
		if (!is_done_bonus_v(cube, ray, (int)ray->rx, (int)ray->ry))
		{
			ray->distv = find_dist(ray, cube->player);
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
		ray->flag = 0;
	}
	else if (cos(degtorad(ray->ra)) < -0.001)
	{
		ray->rx = ((int)cube->player.px) - 0.0001;
		ray->ry = (cube->player.px - ray->rx) * tanv + cube->player.py;
		ray->xo = -1;
		ray->yo = -ray->xo * tanv;
		ray->flag = 0;
	}
	else
	{
		ray->rx = cube->player.px;
		ray->ry = cube->player.py;
		ray->flag = 1;
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
		ray->flag = 0;
	}
	else if (sin(degtorad(ray->ra)) < -0.001)
	{
		ray->ry = ((int)cube->player.py) + 1;
		ray->rx = (cube->player.py - ray->ry) * tanv + cube->player.px;
		ray->yo = 1;
		ray->xo = -ray->yo * tanv;
		ray->flag = 0;
	}
	else
	{
		ray->rx = cube->player.px;
		ray->ry = cube->player.py;
		ray->flag = 1;
	}
}

void	draw_ray(t_cube *cube)
{
	t_ray	ray;
	int		i;
	t_line	line;

	i = -1;
	ray = init_ray(cube->player);
	while (++i < WIDTH)
	{
		set_ray(&ray);
		draw_horizontal(cube, &ray, tan(degtorad(ray.ra)));
		dda_h(cube, &ray);
		ray.vx = ray.rx;
		ray.vy = ray.ry;
		draw_vertical(cube, &ray, 1.0 / tan(degtorad(ray.ra)));
		dda_v(cube, &ray);
		setup_ray(&ray);
		draw_3d(cube, ray, i);
		line = init_line(cube->player.px * cube->map->scale, cube->player.py * cube->map->scale, ray.rx * cube->map->scale, ray.ry * cube->map->scale);
		draw_line(cube->image, line, pixel(255,0,0,255));
		ray.ra = fixang(ray.ra + (double)FPOV / (double)WIDTH);
	}
}
