/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:15:32 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/18 16:59:00 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_check
{
	int	current_row;
	int	current_col;
	int	direction_row;
	int	direction_col;
} t_check;

typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_cube
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_map		*map;
	int			max_width;
	int			max_height;
}	t_cube;

#endif
