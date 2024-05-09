/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:21:46 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/09 13:52:59 by muhakose         ###   ########.fr       */
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
	init_door(cube);
}

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
