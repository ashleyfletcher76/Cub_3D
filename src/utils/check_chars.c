/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:49:25 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/07 18:00:54 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	correct_chars(char c)
{
	if (c == '0' || c == '1' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == ' ' || c == 9
		|| c == '\r' || c == '\t' || c == '\v' || c == '\f')
		return (1);
	return (-1);
}

int	map_valid_chars(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '1')
		return (1);
	return (0);
}

int	edge_conditions(char c)
{
	if (c == '\0' || c == '\n' || c == ' ')
		return (0);
	return (1);
}
