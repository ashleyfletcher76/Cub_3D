/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:21:46 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/18 12:40:50 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "structs.h"

void	leaks(void)
{
	system("leaks Cube3D");
}

int	main(int argc, char **argv)
{
	t_cube	temp_cube;
	t_cube	*cube;

	temp_cube = check_args(argc, argv);
	printf("width = %d\n", temp_cube.max_width);
	printf("height = %d\n", temp_cube.max_height);
	init_cube(&cube, &temp_cube);
	init_map(cube);
	init_mlx(cube);
	mlx_loop_hook(cube->mlx, hook, cube);
	mlx_loop(cube->mlx);
	mlx_terminate(cube->mlx);
	atexit(leaks);
	final_free(cube);
	return (EXIT_SUCCESS);
}
