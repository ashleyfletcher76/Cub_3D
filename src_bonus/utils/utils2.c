/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:58:07 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/10 11:10:58 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_defines(void)
{
	if (WIDTH == 0 || HEIGHT == 0 || PI != 3.1415926535 || PIXEL_PER_CELL != 15
		|| PIDIR != 0.78539816337 || DR != 0.06111111111
		|| MIN_MAP_SIZE != 300 || MAX_MAP_SIZE != 1000 || MAPSIZE != 64
		|| FPOV != 66 || ROTATIONSPEED != 3 || MOVESPEED != 0.05 || STOP != 2)
	{
		ft_putendl_fd("You tried to change our values go away", 2);
		exit(-1);
	}
}
