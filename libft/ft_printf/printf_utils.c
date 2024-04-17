/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:48:19 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/01 11:54:41 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar_custom(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}

int	putstr(char *str, int fd)
{
	int	i;
	int	check;

	i = 0;
	if (str == NULL)
	{
		check = write(fd, "(null)", 6);
		if (check == -1)
			return (-1);
		else
			return (6);
	}
	while (str[i])
	{
		check = putchar_custom(str[i], fd);
		if (check == -1)
			return (-1);
		i++;
	}
	return (i);
}

// size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	size_t	i;
// 	char	chr;

// 	i = 0;
// 	chr = (char)c;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == chr)
// 			return ((char *)s + i);
// 		i++;
// 	}
// 	if (chr == '\0')
// 		return ((char *)s + i);
// 	return (NULL);
// }
