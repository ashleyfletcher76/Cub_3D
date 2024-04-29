/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:21:46 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/29 16:34:34 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "structs.h"

void	leaks(void)
{
	system("leaks cub3D");
}

int	main(int argc, char **argv)
{
	t_cube	temp_cube;
	t_cube	*cube;

	//atexit(leaks);
	temp_cube = check_args(argc, argv);
	init_cube(&cube, &temp_cube);
	init_map(cube);
	parse_map(cube, argv[1]);
	check_map_perimeter(cube);
	//print_map(cube);
	init_mlx(cube);
	init_player(cube);
	draw_pixel(cube);
	mlx_loop_hook(cube->mlx, hook, cube);
	mlx_loop_hook(cube->mlx, user_input, cube);
	mlx_loop(cube->mlx);
	mlx_terminate(cube->mlx);
	final_free(cube);
	return (EXIT_SUCCESS);
}
