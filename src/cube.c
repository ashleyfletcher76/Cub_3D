/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:21:46 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/17 13:50:04 by asfletch         ###   ########.fr       */
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
	t_cube cube;

	check_args(argc, argv, &cube);
	init_mlx(&cube);
	mlx_loop_hook(cube.mlx, hook, &cube);
	mlx_loop(cube.mlx);
	mlx_terminate(cube.mlx);
	atexit(leaks);
	return (EXIT_SUCCESS);
}
