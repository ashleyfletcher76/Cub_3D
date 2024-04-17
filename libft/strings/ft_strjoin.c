/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:46:37 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/10 12:43:49 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*temp;

	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) +1);
	if (!result)
		return (NULL);
	temp = result;
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	while (*s2)
	{
		*temp = *s2;
		temp++;
		s2++;
	}
	*temp = '\0';
	return (result);
}
//once s1 is finished, moves to s2
//preserves starting point of result, result++ points to end of str
