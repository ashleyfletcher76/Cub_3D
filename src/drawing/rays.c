/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:53:18 by muhakose          #+#    #+#             */
/*   Updated: 2024/04/22 13:04:16 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

void	draw_rays(t_cube *cube)
{
	int		r,mx,my,dof;
	float	rx,ry,ra,xo,yo;
	float	aTan;
	float	line[4];

	ra = cube->player.pa;
	r = 0;
	while (r < 1)
	{
		dof = 0;
		if (ra == 0 || ra == PI)
		{
			rx = cube->player.px;
			ry = cube->player.py;
			dof = 8;
		}
		else
			aTan = -1/tan(ra);
		if (ra > PI)
		{
			ry = cube->player.py - 0.0001;
			rx = cube->player.px - 64;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < PI)
		{
			ry = cube->player.py + 0.0001;
			rx = cube->player.px + 64;
			yo = 64;
			xo = -yo * aTan;
		}
		while (dof < 8)
		{
			mx = (int) (rx) / 64;
			my = (int) (ry) / 64;
			if ((mx >= 0 && mx < 8) && (my >= 0 && my < 8) && cube->map->map[my][mx] == '1') // hit wall
				dof = 8;
			else
			{
				rx += xo;
				ry += yo;
				dof +=1; // next line 
			}
		}
		line[0] = cube->player.px;
		line[1] = cube->player.py;
		line[2] = rx;
		line[3] = ry;
		draw_line(cube->image, line, pixel(255, 0 , 255 , 0));
		r++;
	}
}
