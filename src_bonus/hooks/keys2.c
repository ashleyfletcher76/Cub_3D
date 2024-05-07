/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:40:15 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/07 18:03:56 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	key_a(t_cube *cube)
{
	double	newposx;
	double	newposy;

	newposx = cube->player.px;
	newposy = cube->player.py;
	newposx += sin(degtorad(cube->player.pa)) * MOVESPEED * STOP;
	newposy += cos(degtorad(cube->player.pa)) * MOVESPEED * STOP;
	if (is_wall_collision(cube, newposx, newposy))
		return ;
	cube->player.px = cube->player.px + sin(degtorad(cube->player.pa))
		* MOVESPEED;
	cube->player.py = cube->player.py + cos(degtorad(cube->player.pa))
		* MOVESPEED;
}

void	key_d(t_cube *cube)
{
	double	newposx;
	double	newposy;

	newposx = cube->player.px;
	newposy = cube->player.py;
	newposx += -sin(degtorad(cube->player.pa)) * MOVESPEED * STOP;
	newposy += -cos(degtorad(cube->player.pa)) * MOVESPEED * STOP;
	if (is_wall_collision(cube, newposx, newposy))
		return ;
	cube->player.px = cube->player.px - sin(degtorad(cube->player.pa))
		* MOVESPEED;
	cube->player.py = cube->player.py - cos(degtorad(cube->player.pa))
		* MOVESPEED;
}

void	mouse_left(t_cube *cube)
{
	cube->player.pa -= 2;
	cube->player.pa = fixang(cube->player.pa);
	cube->player.pdx = cos(degtorad(cube->player.pa));
	cube->player.pdy = -sin(degtorad(cube->player.pa));
}

void	mouse_right(t_cube *cube)
{
	cube->player.pa += 2;
	cube->player.pa = fixang(cube->player.pa);
	cube->player.pdx = cos(degtorad(cube->player.pa));
	cube->player.pdy = -sin(degtorad(cube->player.pa));
}
