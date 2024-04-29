/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/04/29 11:21:59 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include "structs.h"
# include "../libft/includes/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define PI 3.1415926535
# define PIDIR 3.1415926535 / 4
# define DR 0.0174533

# define WIDTH 1080
# define HEIGHT 720

# define MAPSIZE 32
# define FPOV 60

//check args
t_cube	check_args(int argc, char **argv);
t_cube	check_map(char *map, t_cube *temp_cube);
void	check_invalid_chars(t_cube *temp_cube, char *line);
void	check_map_perimeter(t_cube *cube);
void	multiple_start_pos(t_cube *cube);
int		check_empty_line(t_cube *cube, char *line);

//get map details
void	find_map_width(char *line, t_cube *temp_cube);

//map parsing
t_cube	parse_map(t_cube *cube, char *map);
void	new_map(t_cube *cube, int index);
void	get_west_east(t_cube *cube, char *line, int index);
void	get_north_south(t_cube *cube, char *line, int index);
void	get_floor_ceiling(t_cube *cube, char *line, int index);
void	flood_fill(t_cube *cube, int x, int y);
int		add_map_conditions(t_cube *cube, char *line, int row);
int		get_details(t_cube *cube, char *line);
t_type	get_state(char *line);
int		check_details(t_cube *temp_cube, char *line);

//initialization
int32_t	init_mlx(t_cube *cube);
void	init_cube(t_cube **cube, t_cube *temp_cube);
void	init_map(t_cube *cube);
void	init_player(t_cube *cube);
t_line	init_line(float beginx, float beginy, float endx, float endy);
void	init_default_player(t_cube *cube);
void	reset_players_values(t_cube *cube);
void	hook(void *param);

//drawing processes
void	draw_ray(t_cube *cube);
int		draw_line(mlx_image_t *image, t_line line, float color);
void	draw_pixel(t_cube *cube);
void	find_pl_pos(t_cube *cube);
int		find_pos(t_cube *cube, char c);
void	two_d_map(void *param);
void	put_wall(t_cube *cube, t_line line, t_ray ray);
void	draw_3d(t_cube *cube, t_ray ray, int i);
int32_t	pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	user_input(void *param);

//gameplay
int		is_wall(t_cube *cube, int x, int y);

//utils
void	print_error_exit(int flag);
void	free_print_exit(t_cube *cube, int flag, int i);
void	free_print_exit_two(t_cube *cube, t_point *stack, int flag);
void	final_free(t_cube *cube);
void	free_rgb(char **rgb);
void	free_num_rgb(t_cube *cube);
void	null_ceiling(t_cube *cube);
void	check_if_details(t_cube *temp_cube);
void	print_map(t_cube *cube);

//char checkers
int		correct_chars(char c);
int		map_valid_chars(char c);
int		edge_conditions(char c);

void	compare_textures(t_cube *cube);
void	convert_floor(t_cube *cube);
void	convert_ceiling(t_cube *cube);
void	convert_integers(t_cube *cube, char **rgb, int count, int flag);
int		count_double(char **rgb);

#endif
