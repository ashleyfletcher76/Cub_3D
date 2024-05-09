/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:55:02 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/09 13:12:23 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_guns(t_cube *cube)
{
	cube->gun.gun_t = mlx_load_png(PATH1);
	if (!cube->gun.gun_t)
		free_print_exit_three(cube, 2);
	cube->gun.gun = mlx_texture_to_image(cube->mlx, cube->gun.gun_t);
	if (!cube->gun.gun)
		free_print_exit_three(cube, 2);
	cube->gun.gun2_t = mlx_load_png(PATH2);
	if (!cube->gun.gun2_t)
		free_print_exit_three(cube, 2);
	cube->gun.gun2 = mlx_texture_to_image(cube->mlx, cube->gun.gun2_t);
	if (!cube->gun.gun2)
		free_print_exit_three(cube, 2);
	mlx_delete_texture(cube->gun.gun2_t);
	mlx_image_to_window(cube->mlx, cube->gun.gun, 0, 0);
}

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
	cube->texture.teleport = mlx_load_xpm42("./images/ready/teleport.xpm42");
	if (!cube->texture.teleport)
		free_print_exit_three(cube, 0);
	cube->texture.teleport_tex = &cube->texture.teleport->texture;
}
