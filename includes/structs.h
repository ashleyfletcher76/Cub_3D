/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:15:32 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/25 14:47:47 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_default
{
	float	px;
	float	py;
	float	pdx;
	float	pdy;
}	t_default;

typedef struct s_line
{
	float	begin_x;
	float	begin_y;
	float	end_x;
	float	end_y;
}	t_line;

typedef struct s_ray
{
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	int		mx;
	int		my;
}	t_ray;

typedef struct s_player
{
	float			px;
	float			py;
	float			opx;
	float			opy;
	float			pdx;
	float			pdy;
	float			pa;
	float			color;
	char			d;
	mlx_image_t		*p_img;
}	t_player;

typedef struct s_map
{
	char	**map;
	int		empty_col;
	int		start_x;
	int		start_y;
	int		grid_size;
}	t_map;

typedef struct s_cube
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_map		*map;
	t_player	player;
	t_line		line;
	t_default	player_default;
	int			map_size;
	int			max_width;
	int			max_height;
	int			width_nospace;
}	t_cube;

#endif
