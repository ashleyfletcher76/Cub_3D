/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:31:23 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/13 12:55:47 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	free_png(t_cube *cube)
{
	if (cube->gun.gun_t)
		mlx_delete_texture(cube->gun.gun_t);
	if (cube->gun.gun2_t)
		mlx_delete_texture(cube->gun.gun2_t);
	if (cube->texture.teleport_tex)
		mlx_delete_texture(cube->texture.teleport_tex);
}

static void	free_xpm(t_cube *cube)
{
	if (cube->texture.north)
		mlx_delete_xpm42(cube->texture.north);
	if (cube->texture.south)
		mlx_delete_xpm42(cube->texture.south);
	if (cube->texture.east)
		mlx_delete_xpm42(cube->texture.east);
	if (cube->texture.west)
		mlx_delete_xpm42(cube->texture.west);
	if (cube->texture.mas)
		mlx_delete_xpm42(cube->texture.mas);
	if (cube->texture.ash)
		mlx_delete_xpm42(cube->texture.ash);
	if (cube->texture.door_open)
		mlx_delete_xpm42(cube->texture.door_open);
	if (cube->texture.door_half)
		mlx_delete_xpm42(cube->texture.door_half);
	if (cube->texture.door_close)
		mlx_delete_xpm42(cube->texture.door_close);
}

void	free_rgb(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		free (rgb[i]);
		i++;
	}
	free (rgb);
}

static void	free_details(t_cube *cube)
{
	if (cube->details->north)
		free (cube->details->north);
	if (cube->details->south)
		free (cube->details->south);
	if (cube->details->east)
		free (cube->details->east);
	if (cube->details->west)
		free (cube->details->west);
	if (cube->details->floor)
		free (cube->details->floor);
	if (cube->details->ceiling)
		free (cube->details->ceiling);
	if (cube->details)
		free (cube->details);
	cube->details = NULL;
}

void	final_free(t_cube *cube)
{
	int	x;

	if (cube != NULL)
	{
		if (cube->map != NULL && cube->map->map != NULL)
		{
			x = -1;
			while (++x < cube->max_height)
				free (cube->map->map[x]);
		}
		free (cube->map->map);
	}
	free_details(cube);
	free_xpm(cube);
	free_png(cube);
	free (cube->map);
	free (cube);
}
