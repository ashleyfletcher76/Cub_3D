/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:40:15 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/09 14:44:51 by muhakose         ###   ########.fr       */
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
	cube->player.px += sin(degtorad(cube->player.pa)) * MOVESPEED;
	cube->player.py += cos(degtorad(cube->player.pa)) * MOVESPEED;
}

void	key_d(t_cube *cube)
{
	double	newposx;
	double	newposy;

	newposx = cube->player.px;
	newposy = cube->player.py;
	newposx -= sin(degtorad(cube->player.pa)) * MOVESPEED * STOP;
	newposy -= cos(degtorad(cube->player.pa)) * MOVESPEED * STOP;
	if (is_wall_collision(cube, (int)newposx, (int)newposy))
		return ;
	cube->player.px -= sin(degtorad(cube->player.pa)) * MOVESPEED;
	cube->player.py -= cos(degtorad(cube->player.pa)) * MOVESPEED;
}
