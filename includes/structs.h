/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/04/30 14:21:14 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef enum s_type
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	FLOOR,
	CEILING,
	END
}	t_type;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_default
{
	double	px;
	double	py;
	double	pdx;
	double	pdy;
}	t_default;

typedef struct s_line
{
	double	begin_x;
	double	begin_y;
	double	end_x;
	double	end_y;
}	t_line;

typedef struct s_ray
{
	double	rx;
	double	ry;
	double	ra;
	double	xo;
	double	yo;
	double	dist;
	int		mx;
	int		my;
}	t_ray;

typedef struct s_player
{
	double			px;
	double			py;
	double			opx;
	double			opy;
	double			pdx;
	double			pdy;
	double			pa;
	double			color;
	char			d;
	mlx_image_t		*p_img;
}	t_player;

typedef struct s_details
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	int		*gen_rgb;
	int32_t	floor_rgb;
	int32_t	ceiling_rgb;
}	t_details;

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
	mlx_texture_t	wall_tex;
	xpm_t		*wall_xpm;
	t_map		*map;
	t_player	player;
	t_line		line;
	t_default	player_default;
	t_details	*details;
	bool		map_start;
	int			details_found;
	int			max_width;
	int			max_height;
}	t_cube;

#endif
