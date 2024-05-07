/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:21:46 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/07 18:01:29 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	leaks(void)
{
	system("leaks cub3D");
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
	init_cube(&cube, &temp_cube);
	init_map(cube);
	parse_map(cube, argv[1]);
	check_map_perimeter(cube);
	init_mlx(cube);
	init_2d_map(cube);
	init_player(cube);
	init_textures(cube);
	mlx_key_hook(cube->mlx, user_input, cube);
	mlx_loop_hook(cube->mlx, user_input_two, cube);
	mlx_loop(cube->mlx);
	mlx_terminate(cube->mlx);
	final_free(cube);
	return (EXIT_SUCCESS);
}
