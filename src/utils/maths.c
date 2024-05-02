/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:49:23 by muhakose          #+#    #+#             */
/*   Updated: 2024/05/02 10:49:43 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "cub3d.h"

double	degtorad(float a)
{
	return (a * PI / 180.0);
}

double	fixang(float a)
{
	if (a > 359)
	a -= 360;
	return (a);
}