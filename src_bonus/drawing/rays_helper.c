/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:08:25 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/09 17:00:15 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	ray.tex = '.';
	ray.flag = 0;
	ray.ra = fixang(player.pa - FPOV / 2);
	return (ray);
}

void	set_ray(t_ray *ray)
{
	ray->shade = 1;
	ray->tex = '.';
	ray->disth = 10000;
	ray->distv = 10000;
	ray->distdv = 10000;
	ray->distdh = 10000;
}

int	is_done_bonus_v(t_cube *cube, t_ray *ray, int x, int y)
{
	if (x < 0 || x >= cube->max_width)
		return (false);
	if (y < 0 || y >= cube->max_height)
		return (false);
	if (cube->map->map[y][x] == 'L')
		ray->distdv = find_dist(ray, cube->player);
	if (cube->map->map[y][x] == '1' || cube->map->map[y][x] == 'Z')
		return (false);
	return (true);
}

int	is_done_bonus_h(t_cube *cube, t_ray *ray, int x, int y)
{
	if (x < 0 || x >= cube->max_width)
		return (false);
	if (y < 0 || y >= cube->max_height)
		return (false);
	if (cube->map->map[y][x] == 'L')
		ray->distdh = find_dist(ray, cube->player);
	if (cube->map->map[y][x] == '1' || cube->map->map[y][x] == 'Z')
		return (false);
	return (true);
}
