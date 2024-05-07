/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:36:13 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/07 16:55:39 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs_bonus.h"
#include "cub3d_bonus.h"

void	reset_players_values(t_cube *cube)
{
	cube->player.px = cube->player_default.px;
	cube->player.py = cube->player_default.py;
	cube->player.pdx = cube->player_default.pdx;
	cube->player.pdy = cube->player_default.pdy;
	cube->player.pa = cube->player_default.pa;
}
