/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:55:41 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/26 15:19:36 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	while (*s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	str[i] = '\0';
	return (str);
}

//creates space for a copy of s1
