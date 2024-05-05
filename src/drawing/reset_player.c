/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:36:13 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/05 12:19:24 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

void	reset_players_values(t_cube *cube)
{
	cube->player.px = cube->player_default.px;
	cube->player.py = cube->player_default.py;
	cube->player.pdy = cube->player_default.pdx;
	cube->player.pdx = cube->player_default.pdy;
	cube->player.pa = cube->player_default.pa;
}
