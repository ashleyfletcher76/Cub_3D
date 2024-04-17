/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:22:05 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/17 12:38:46 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# define WIDTH 1920
# define HEIGHT 1080

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structs.h"
#include "../libft/includes/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"

//check args
void	check_args(int argc, char **argv);
int		check_map(char *map);
void	check_invalid_chars(char *line);
void	print_error(int flag);

//initialization
int32_t	init_mlx(t_cube *cube);
void	hook(void *param);

#endif
