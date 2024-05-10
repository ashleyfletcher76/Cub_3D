/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:04:41 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/10 12:42:25 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	char		*d;

	s = src;
	d = dst;
	if (src == dst)
		return (dst);
	if (s < d)
	{
		s += len;
		d += len;
		while (len--)
		{
			*(--d) = *(--s);
		}
	}
	else
	{
		ft_memcpy(d, s, len);
	}
	return (dst);
}
//+= starts the pointer at the end
//*(--d) decrements the value concurrently with s
// copies data from src to dst without destroying
