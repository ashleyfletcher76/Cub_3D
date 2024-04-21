/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:15:32 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/21 12:32:00 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_player
{
	int	px;
	int	py;
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
	int			max_width;
	int			max_height;
	int			width_nospace;
}	t_cube;

#endif
