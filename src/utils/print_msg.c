/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:33:10 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/17 12:36:16 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cube3d.h"

void	print_error(int flag)
{
	if (flag == 0)
		ft_putendl_fd("Incorrect arguments.", 2);
	else if (flag == 1)
		ft_putendl_fd("Invalid map.", 2);
	exit(EXIT_FAILURE);
}
