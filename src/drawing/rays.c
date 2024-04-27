/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:53:18 by muhakose          #+#    #+#             */
/*   Updated: 2024/04/27 14:06:43 by muhakose         ###   ########.fr       */
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
	ray.xl = 0;
	ray.yl = 0;
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

void	put_wall(t_cube *cube, t_line line, t_ray ray)
{
	if (ray.ra > PIDIR && ray.ra <= 3 * PIDIR)
		draw_line(cube->image, line, pixel(255, 0, 0, 255)); // South red
	else if (ray.ra > 3 * PIDIR && ray.ra <= 5 * PIDIR)
		draw_line(cube->image, line, pixel(255, 0, 255, 255)); // West magenta
	else if (ray.ra > 5 * PIDIR && ray.ra <= 7 * PIDIR)
		draw_line(cube->image, line, pixel(0, 0, 0, 255)); // North black
	else
		draw_line(cube->image, line, pixel(255, 255, 0, 255)); // East yellow 

}

void	draw_3d(t_cube *cube, t_ray ray, int i)
{
	t_line	line;
	float	dist = 0;
	float	lineO;
	float	lined;

	float ca = cube->player.pa - ray.ra;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	else if (ca < 0)
		ca += 2 * PI;

	if (ray.xl > ray.yl)
		lined = ray.xl;
	else
		lined = ray.yl;
	lined = lined * cos(ca);
	dist = 320 * MAPSIZE / lined;
	lineO = 320 - dist / 2;
	if (dist > 320)
		dist = 320;
	int x = -1;
	while (++x < MAPSIZE)
	{
		line = init_line(MAPSIZE * (cube->max_width + i) + x, lineO, MAPSIZE * (cube->max_width + i) + x, dist + lineO);
		put_wall(cube, line, ray);
	}
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
	while (++i < FPOV)
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
		draw_line(cube->image, line, pixel(0, 0, 255, 255));
		draw_3d(cube, ray, i);
		ray.ra += DR;
	}
}
