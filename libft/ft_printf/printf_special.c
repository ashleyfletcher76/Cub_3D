/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_special.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:21:35 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/01 11:48:00 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(unsigned long nbr, const char *base)
{
	int	count;
	int	check;

	count = 0;
	if (nbr >= 16)
	{
		count = print_hexa(nbr / 16, base);
		if (count == -1)
			return (-1);
	}
	check = putchar_custom(base[nbr % 16], 1);
	if (check == -1)
		return (-1);
	return (count + 1);
}

//base[n % 16] defines the position according to the remainder of the nbr / 16
//base[0] = 0 || base[15] == F

int	print_pointer(void *ptr)
{
	unsigned long	ptr_value;
	int				count;
	int				check;

	count = 0;
	ptr_value = (unsigned long)ptr;
	check = putstr("0x", 1);
	if (check == -1)
		return (-1);
	count += 2;
	if (!ptr)
	{
		check = putchar_custom('0', 1);
		if (check == -1)
			return (-1);
		count += 1;
	}
	else
		count += print_hexa(ptr_value, "0123456789abcdef");
	return (count);
}
