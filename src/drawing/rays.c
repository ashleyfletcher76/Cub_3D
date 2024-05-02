/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:53:18 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/02 11:27:05 by muhakose         ###   ########.fr       */
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

	i = -1;
	ray = init_ray(cube->player);
	while (++i < 1)
	{
		set_ray(&ray, cube->player.px, cube->player.py);
		while (is_done(cube, ray.mx, ray.my))
		{
			ray.mx = (int)(ray.rx) / MAPSIZE;
			ray.my = (int)(ray.ry) / MAPSIZE;
			ray.rx += ray.xo;
			ray.ry += ray.yo;
		}
		find_dist(&ray, cube->player);
		line = init_line(cube->player.px, cube->player.py, ray.rx, ray.ry);
		draw_line(cube->image, line, pixel(0, 255, 0, 255));
		//draw_3d(cube, ray, i);
		if ((ray.ra >= 7 * M_PI / 4 && ray.ra <= 2 * M_PI) || (ray.ra >= 0 && ray.ra < M_PI / 4))
			printf("N\n");
		else if (ray.ra > M_PI && ray.ra <= 3 * M_PI)
			printf("W\n");
		else if (ray.ra > 3 * M_PI && ray.ra <= 5 * M_PI)
			printf("S\n");
		else
			printf("E\n");
		ray.ra += DR;
		if (ray.ra < 0)			{ray.ra += 2 * PI;}
		if (ray.ra > 2 * PI)	{ray.ra -= 2 * PI;}
	}
}


//void	vertical_rays(t_cube *cube, t_ray *ray)
//{
//	float atan = -tan(ray->ra);
//	if(cos((ray->ra)) > 0.001)
//	{
//		ray->rx = cube->player.px;
//		ray->ry = cube->player.py;
//		ray->xo = 1;
//		ray->yo = -ray->xo * atan;
//		printf("here\n");
//	}
//	else if(cos((ray->ra)) < -0.001)
//	{
//		ray->rx = cube->player.px;
//		ray->ry = cube->player.py;
//		ray->xo = -1;
//		ray->yo = -ray->xo * atan;
//		printf("nothere\n");
//	}
//	else 
//	{
//		ray->rx = cube->player.px;
//		ray->ry = cube->player.py;
//		ray->xo = 0;
//		ray->yo = 1;
//	}
//	while(is_done(cube, ray->mx, ray->my))
//	{
//		ray->mx = (int)ray->rx / MAPSIZE;
//		ray->my = (int)ray->ry / MAPSIZE;
//		ray->rx += ray->xo;
//		ray->ry += ray->yo;
//	}
//	t_line line = init_line(cube->player.px, cube->player.py, ray->rx, ray->ry);
//	draw_line(cube->image, line, pixel(255,0,0,255));
//}

//void	horizontal_rays(t_cube *cube, t_ray *ray)
//{
	
//}

//void	draw_ray(t_cube *cube)
//{
//	t_ray ray = init_ray(cube->player);
//	int i = 0;

//	while (i < 1)
//	{
//		vertical_rays(cube, &ray);
//		//horizontal_rays(cube, &ray);

		
//		i++;
//	}


//}

