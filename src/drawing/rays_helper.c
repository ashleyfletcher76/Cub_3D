/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:08:25 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/07 17:58:48 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ray.shade = 1;
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
