/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:19:15 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/29 16:18:28 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

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
