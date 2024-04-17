/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:33:48 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/09 11:34:22 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	count_words(const char *str, char delim)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != delim)
		{
			while (str[i] && str[i] != delim)
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

void	free_allocated(char **arr, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		free(arr[i]);
	free(arr);
}
