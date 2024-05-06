/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:44:12 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/05 15:16:27 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

void	key_up(t_cube *cube)
{
	double newposx;
	double newposy;

	newposx = cube->player.px;
	newposy = cube->player.py;
	newposx += cube->player.pdx * MOVESPEED;
	newposy += cube->player.pdy * MOVESPEED;
	if (newposx < 0 || newposx >= cube->max_width)
		return ;
	if (newposy < 0 || newposy >= cube->max_height)
		return ;
	if (is_wall_forward(cube, newposx, newposy, 0))
		return ;
	cube->player.px = newposx;
	cube->player.py = newposy;
}

void	key_down(t_cube *cube)
{
	double newposx;
	double newposy;

	newposx = cube->player.px;
	newposy = cube->player.py;
	newposx -= cube->player.pdx * MOVESPEED;
	newposy -= cube->player.pdy * MOVESPEED;
	if (newposx < 0 || newposx >= cube->max_width)
		return ;
	if (newposy < 0 || newposy >= cube->max_height)
		return ;
	if (is_wall_back(cube, newposx, newposy, 0))
		return ;
	cube->player.px = newposx;
	cube->player.py = newposy;
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
