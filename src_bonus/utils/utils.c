/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:19:15 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/07 16:57:44 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs_bonus.h"
#include "cub3d_bonus.h"

int	check_numbers(int *rgb, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (-1);
	}
	return (0);
}

void	check_if_details(t_cube *temp_cube)
{
	if (temp_cube->max_width < 1)
		print_error_exit(1);
}

int	count_double(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
		i++;
	return (i);
}

void	draw_images_xpm42(t_cube *cube, mlx_texture_t tex)
{
	uint32_t n;
	uint32_t m;

	n = 0;
	while (n < tex.width)
	{
		m = 0;
		while (m < tex.height)
		{
			int index = (n * tex.width + m) * 4;
			uint8_t *pixels = &tex.pixels[index];
			int color = pixel(pixels[0], pixels[1] ,pixels[2], pixels[3]);
			mlx_put_pixel(cube->image, n, m, color);
			m++;
		}
		n++;
	}
}

t_point	get_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}
