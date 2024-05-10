/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:03:11 by asfletch          #+#    #+#             */
/*   Updated: 2023/12/10 12:40:59 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnth(t_list *lst, int n)
{
	int	i;
	int	size;
	int	target;

	i = 0;
	size = ft_lstsize(lst);
	target = size - n;
	if (target < 0 || target >= size)
		return (NULL);
	while (i < target)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
