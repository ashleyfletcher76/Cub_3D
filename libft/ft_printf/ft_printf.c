/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:07:21 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/01 11:49:02 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversion(const char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'p')
		return (print_pointer(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (print_digit(va_arg(args, int), 1));
	if (c == 'u')
		return (print_unsigned(va_arg(args, unsigned int), 1));
	if (c == 'x')
		return (print_hexa(va_arg(args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (print_hexa(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (c == '%')
	{
		if (putchar_custom('%', 1) == -1)
			return (-1);
		count++;
	}
	return (0);
}

static int	simple_conversion(const char specifier, va_list args)
{
	int		count;
	char	*str;

	count = 0;
	if (specifier == 'c')
	{
		if (putchar_custom(va_arg(args, int), 1) == -1)
			return (-1);
		count++;
	}
	else if (specifier == 's')
	{
		str = va_arg(args, char *);
		count = print_str(str, 1);
		if (count == -1)
			return (-1);
	}
	else
		count = conversion(specifier, args);
	return (count);
}

static int	process_specifier(const char *str, int *i, va_list args)
{
	int	count;
	int	check;

	count = 0;
	check = 0;
	if (str[*i] == '%' && str[*i++] == '%')
	{
		if (putchar_custom('%', 1) == -1)
			return (-1);
		count = 1;
	}
	else if (ft_strchr("cspdiuxX", str[*i]))
	{
		check = simple_conversion(str[*i], args);
		if (check == -1)
			return (-1);
		count += check;
	}
	return (count);
}

static int	helper_printf(va_list args, const char *str)
{
	int		print_count;
	int		i;

	print_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			print_count += process_specifier(str, &i, args);
			if (print_count == -1)
				return (-1);
		}
		else
		{
			if (putchar_custom(str[i], 1) == -1)
				return (-1);
			print_count++;
		}
		i++;
	}
	return (print_count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_count;

	va_start(args, str);
	print_count = helper_printf(args, str);
	if (print_count == -1)
	{
		va_end(args);
		return (-1);
	}
	va_end(args);
	return (print_count);
}

//we keep a count to ensure predictable behaviour and check for errors
