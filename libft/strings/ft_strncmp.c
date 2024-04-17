/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:18:49 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/10 12:44:18 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	num1;
	unsigned char	num2;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		num1 = (unsigned char)s1[i];
		num2 = (unsigned char)s2[i];
		if (num1 != num2)
		{
			return (num1 - num2);
		}
		i++;
	}
	return (0);
}
//compares up to n bytes
