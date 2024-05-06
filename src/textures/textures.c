/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:55:02 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/06 11:49:40 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

void	init_textures(t_cube *cube)
{
	cube->texture.north = mlx_load_xpm42(cube->details->north);
	if (!cube->texture.north)
		free_print_exit_three(cube, 0);
	cube->texture.north_tex = cube->texture.north->texture;
	cube->texture.south = mlx_load_xpm42(cube->details->south);
	if (!cube->texture.south)
		free_print_exit_three(cube, 0);
	cube->texture.south_tex = cube->texture.south->texture;
	cube->texture.east = mlx_load_xpm42(cube->details->east);
	if (!cube->texture.east)
		free_print_exit_three(cube, 0);
	cube->texture.east_tex = cube->texture.east->texture;
	cube->texture.west = mlx_load_xpm42(cube->details->west);
	if (!cube->texture.west)
		free_print_exit_three(cube, 0);
	cube->texture.west_tex = cube->texture.west->texture;
}
