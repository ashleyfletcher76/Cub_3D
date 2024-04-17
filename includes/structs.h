/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:15:32 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/17 10:32:28 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_cube
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_cube;


#endif
