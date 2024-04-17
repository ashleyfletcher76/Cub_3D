/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:04:05 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/10 12:42:44 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	check_overflow(long int converted_int, int sign)
{
	if (sign == 1 && converted_int > INT_MAX)
		return (1);
	if (sign == -1 && converted_int > INT_MAX)
	{
		if (converted_int > INT_MAX + 1L)
			return (1);
		else if (converted_int == INT_MAX + 1L)
			return (0);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	converted_int;

	i = 0;
	sign = 1;
	converted_int = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		|| (str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		converted_int = converted_int * 10 + (str[i] - '0');
		if (check_overflow(converted_int, sign))
			return (0);
		i++;
	}
	return (sign * converted_int);
}
