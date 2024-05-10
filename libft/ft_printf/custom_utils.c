/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:24:51 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/01 11:48:45 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int n, int fd)
{
	int	count;
	int	check;

	count = 0;
	if (n / 10)
	{
		count = print_unsigned(n / 10, fd);
		if (count == -1)
			return (-1);
	}
	check = putchar_custom((n % 10) + '0', fd);
	if (check == -1)
		return (-1);
	return (count + 1);
}

static int	print_negative(int n, int fd)
{
	int	check;

	if (n == -2147483648)
		return (putstr("-2147483648", fd));
	else
	{
		check = putchar_custom('-', fd);
		if (check == -1)
			return (-1);
		n = -n;
		return (print_digit(n, fd) + 1);
	}
}

int	print_digit(int n, int fd)
{
	int	count;
	int	check;

	count = 0;
	if (n < 0)
	{
		check = print_negative(n, fd);
		if (check == -1)
			return (-1);
		return (check);
	}
	if (n >= 10)
	{
		check = print_digit(n / 10, fd);
		if (check == -1)
			return (-1);
		count += check;
	}
	check = putchar_custom((n % 10) + '0', fd);
	if (check == -1)
		return (-1);
	return (count + check);
}

int	print_str(char *str, int fd)
{
	int	check;

	if (str == NULL)
	{
		check = putstr("(null)", fd);
		if (check == -1)
			return (-1);
		return (6);
	}
	else
	{
		check = putstr(str, fd);
		if (check == -1)
			return (-1);
		return (ft_strlen(str));
	}
}
