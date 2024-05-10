/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:54:04 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/07 17:59:18 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_mini_map(t_cube *cube)
{
	if (cube->map->show_map == false)
		cube->map->show_map = true;
	else
		cube->map->show_map = false;
}
