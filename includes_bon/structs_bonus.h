/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:10:38 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/10 11:30:19 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"

enum e_keycode
{
	KEY_UP = 87,
	KEY_DOWN = 83,
	KEY_LEFT = 65,
	KEY_RIGHT = 68,
	RESET = 15,
	ESC = 256,
	KEY_P = 80,
	KEY_M = 77,
	KEY_A = 65,
	KEY_D = 68,
	KEY_S = 83,
	KEY_W = 87
};

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

typedef struct s_gun
{
	mlx_image_t		*gun;
	mlx_texture_t	*gun_t;
	mlx_image_t		*gun2;
	mlx_texture_t	*gun2_t;
}	t_gun;

typedef struct s_texture
{
	xpm_t			*north;
	xpm_t			*south;
	xpm_t			*east;
	xpm_t			*west;
	xpm_t			*teleport;
	xpm_t			*door_open;
	xpm_t			*door_close;
	mlx_texture_t	north_tex;
	mlx_texture_t	south_tex;
	mlx_texture_t	east_tex;
	mlx_texture_t	west_tex;
	mlx_texture_t	*teleport_tex;
	mlx_texture_t	door_open_tex;
	mlx_texture_t	door_close_tex;
}	t_texture;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_mouse
{
	double	x;
	double	y;
}	t_mouse;

typedef struct s_default
{
	double	px;
	double	py;
	double	pdx;
	double	pdy;
	double	pa;

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
	double	vx;
	double	vy;
	double	dhx;
	double	dhy;
	double	dvx;
	double	dvy;
	double	disth;
	double	distv;
	double	distdv;
	double	distdh;
	double	lineoff;
	double	ty_step;
	double	ty_off;
	double	shade;
	double	door_shade;
	int		dist;
	int		flag;
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
	int		mini_width;
	int		mini_height;
	int		scale_width;
	int		scale_height;
	int		scale;
	int		pixel_scale;
	int		draw_width;
	int		draw_height;
	bool	show_map;
}	t_map;

typedef struct s_cube
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	mlx_image_t		*mini;
	xpm_t			*wall_xpm;
	mlx_texture_t	wall_tex;
	t_map			*map;
	t_player		player;
	t_line			line;
	t_default		player_default;
	t_details		*details;
	t_texture		texture;
	t_gun			gun;
	t_mouse			mouse;
	bool			map_start;
	int				details_found;
	int				max_width;
	int				max_height;
}	t_cube;

typedef struct s_check
{
	int		max_width;
	int		max_height;
	int		north;
	int		south;
	int		west;
	int		east;
	int		floor;
	int		ceiling;
	bool	map_start;
}	t_check;

#endif
