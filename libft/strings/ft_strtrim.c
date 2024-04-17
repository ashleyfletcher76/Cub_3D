/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:41:46 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/10 12:44:38 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	len;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (!*s1)
		return (ft_calloc(1, 1));
	len = ft_strlen(s1);
	start = 0;
	end = len - 1;
	while (start < len && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	len = end - start + 1;
	new_str = (char *)malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, s1 + start, len);
	new_str[len] = '\0';
	return (new_str);
}
//calloc makes it null terminated and stops unexpected behaviour
