/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:44:12 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/07 17:59:30 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_up(t_cube *cube)
{
	double	newposx;
	double	newposy;

	newposx = cube->player.px;
	newposy = cube->player.py;
	newposx += cube->player.pdx * MOVESPEED * STOP;
	newposy += cube->player.pdy * MOVESPEED * STOP;
	if (is_wall_collision(cube, newposx, newposy))
		return ;
	cube->player.px += cube->player.pdx * MOVESPEED;
	cube->player.py += cube->player.pdy * MOVESPEED;
}

void	key_down(t_cube *cube)
{
	double	newposx;
	double	newposy;

	newposx = cube->player.px;
	newposy = cube->player.py;
	newposx -= cube->player.pdx * MOVESPEED * STOP;
	newposy -= cube->player.pdy * MOVESPEED * STOP;
	if (is_wall_collision(cube, newposx, newposy))
		return ;
	cube->player.px -= cube->player.pdx * MOVESPEED;
	cube->player.py -= cube->player.pdy * MOVESPEED;
}

void	key_left(t_cube *cube)
{
	cube->player.pa -= ROTATIONSPEED;
	cube->player.pa = fixang(cube->player.pa);
	cube->player.pdx = cos(degtorad(cube->player.pa));
	cube->player.pdy = -sin(degtorad(cube->player.pa));
}

void	key_right(t_cube *cube)
{
	cube->player.pa += ROTATIONSPEED;
	cube->player.pa = fixang(cube->player.pa);
	cube->player.pdx = cos(degtorad(cube->player.pa));
	cube->player.pdy = -sin(degtorad(cube->player.pa));
}
