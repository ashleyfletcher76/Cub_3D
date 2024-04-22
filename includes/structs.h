/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:15:32 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/21 15:00:40 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_player
{
	float			px;
	float			py;
	float			pdx;
	float			pdy;
	float			pa;
	char			d;
	mlx_image_t	*p_img;
}	t_player;

typedef struct s_map
{
	char	**map;
	int		grid_size;
}	t_map;

typedef struct s_cube
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_map		*map;
	t_player	player;
	int			map_size;
	int			max_width;
	int			max_height;
	int			width_nospace;
}	t_cube;

#endif
