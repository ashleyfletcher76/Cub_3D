/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:33:35 by asfletch          #+#    #+#             */
/*   Updated: 2024/05/10 18:44:24 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_type	get_state_begin(char *line)
{
	int	i;

	i = 0;
	while (whitespace_skip(line[i]))
		i++;
	if (line[i] == 'N')
		return (NORTH);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		return (SOUTH);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		return (EAST);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		return (WEST);
	else if (line[i] == 'F')
		return (FLOOR);
	else if (line[i] == 'C')
		return (CEILING);
	else if (line[i] == '\0' || line[i] == '\n')
		return (NEWLINE);
	else
		check_correct_detail_arg(line, i);
	return (END);
}

static void	check_following_char(char *line, char c, int i)
{
	if (c == 'N' && line[i + 1] != 'O' && (line [i + 1] != '\0'
		|| line[i + 1] != '\n'))
		print_error_exit(9);
	else if (c == 'S' && line[i + 1] != 'O' && (line [i + 1] != '\0'
		|| line[i + 1] != '\n'))
		print_error_exit(9);
	else if (c == 'E' && line[i + 1] != 'A' && (line [i + 1] != '\0'
		|| line[i + 1] != '\n'))
		print_error_exit(9);
	else if (c == 'W' && line[i + 1] != 'E' && (line [i + 1] != '\0'
		|| line[i + 1] != '\n'))
		print_error_exit(9);
}

void	check_correct_detail_arg(char *line, int i)
{
	int		j;
	char	*str;

	str = "NSWEFC";
	while (line[i])
	{
		j = 0;
		while (str[j])
		{
			if (line[i] != str[j])
				print_error_exit(9);
			else if (line[i] == str[j])
				check_following_char(line, str[j], i);
			j++;
		}
		i++;
	}
}
