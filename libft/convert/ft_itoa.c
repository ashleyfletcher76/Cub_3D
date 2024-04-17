/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:09:26 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/10 12:43:10 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	check_sign(int n)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	return (sign);
}

static int	num_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		sign;

	sign = check_sign(n);
	len = num_len(n) + (sign == -1);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	len --;
	if (sign == -1)
		str[0] = '-';
	while (len > 0 || (len == 0 && sign == 1))
	{
		str[len] = '0' + (n % 10) * sign;
		n = n / 10;
		if (len == 0)
		{
			break ;
		}
		len--;
	}
	return (str);
}

//goes to zero index when sign was pos or else when neg, zero index is "-"
// * sign always changes to pos because n % 10 stays neg when number was neg
