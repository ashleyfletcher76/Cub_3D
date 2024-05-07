/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:21:46 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/07 17:56:25 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	leaks(void)
{
	system("leaks Bonus");
}

static void	init_mlx_functions(t_cube *cube)
{
	mlx_set_cursor_mode(cube->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_cursor(cube->mlx, mlx_create_std_cursor(MLX_CURSOR_CROSSHAIR));
	mlx_key_hook(cube->mlx, user_input, cube);
	mlx_mouse_hook(cube->mlx, mouse_hook, cube);
	mlx_cursor_hook(cube->mlx, cursour_hook, cube);
	mlx_loop_hook(cube->mlx, user_input_two, cube);
}

static void	init_functions(t_cube *cube)
{
	init_2d_map(cube);
	init_player(cube);
	init_textures(cube);
	init_guns(cube);
}

// static void	check_defines(void)
// {
// 	if (WIDTH == 0 || HEIGHT == 0 || PI != 3.1415926535 || PIXEL_PER_CELL != 15
// 		|| PIDIR != 0.78539816337 || DR != 0.06111111111
// 		|| MIN_MAP_SIZE != 300 || MAX_MAP_SIZE != 1000 || MAPSIZE != 64
// 		|| FPOV != 66 || ROTATIONSPEED != 3 || MOVESPEED != 0.05 || STOP != 5)
// 		{
// 			ft_putendl_fd("You tried to change our values go away", 2);
// 			exit(-1);
// 		}
// }

int	main(int argc, char **argv)
{
	t_cube	temp_cube;
	t_cube	*cube;

	//atexit(leaks);
	//check_defines();
	temp_cube = check_args(argc, argv);
	init_cube(&cube, temp_cube);
	init_map(cube);
	parse_map(cube, argv[1]);
	check_map_perimeter(cube);
	init_mlx(cube);
	init_functions(cube);
	init_mlx_functions(cube);
	mlx_loop(cube->mlx);
	mlx_terminate(cube->mlx);
	final_free(cube);
	return (EXIT_SUCCESS);
}
