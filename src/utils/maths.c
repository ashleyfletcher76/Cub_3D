/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:49:23 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/09 13:32:47 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	degtorad(double a)
{
	return (a * (PI / 180.0));
}

double	fixang(double a)
{
	if (a > 359)
		a -= 360;
	if (a < 0)
		a += 360;
	return (a);
}

double	find_dist(t_ray *ray, t_player player)
{
	double	x;
	double	y;

	x = ray->rx - player.px;
	y = ray->ry - player.py;
	return (sqrt(x * x + y * y));
}
