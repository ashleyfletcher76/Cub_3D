/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 09:59:11 by asfletch          #+#    #+#             */
/*   Updated: 2024/01/23 05:44:17 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join_strings(char *stash, char *buffer)
{
	char	*new_stash;

	if (stash == NULL || buffer == NULL)
		return (NULL);
	new_stash = ft_strjoin(stash, buffer);
	if (new_stash == NULL)
	{
		free (stash);
		return (NULL);
	}
	free (stash);
	return (new_stash);
}
