/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:25:07 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/09 11:45:24 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	main(void)
{
	char	str[] = "hello cruel cruel world";
	char	**result;
	size_t	i = -1;
	size_t	num_words = count_words(str, ' ');

	result = ft_split(str, ' ');
	while (++i < num_words)
		printf("str = %s\n", result[i]);
	i = -1;
	while (++i < num_words)
		free (result[i]);
	free (result);
	return (0);
}

// gcc strings/ft_split.c mem_manip/ft_memcpy.c strings/split_utils.c main.c
// valgrind --leak-check=full --show-leak-kinds=all ./a.out
