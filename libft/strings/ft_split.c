/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:42:50 by asfletch          #+#    #+#             */
/*   Updated: 2024/03/09 11:44:09 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*skip(char *str)
{
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
		str++;
	return (str);
}

static size_t	get_len(const char *str, char delim)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != delim)
		i++;
	return (i);
}

char	*word(char *str, int len)
{
	char *word;
	int	i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static char	**split_helper(char **result, char *str, int len, int i)
{
	result[i] = word(str, len);
	if (!result[i])
	{
		free_allocated(result, (size_t)i);
		return (NULL);
	}
	return (result);
}

char	**ft_split(char *str, char delim)
{
	char **result;
	int	len;
	int	i;
	int	num_words;

	i = 0;
	num_words = count_words(str, delim);
	result = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!result)
		return (NULL);
	str = skip(str);
	while (*str)
	{
		len = get_len(str, delim);
		if (len > 0)
		{
			if (!split_helper(result, str, len, i))
				return (NULL);
			str += len;
			i++;
		}
		str = skip(str);
	}
	result[num_words] = 0;
	return (result);
}

//double pointer, points to array of pointers
//**s checks curr pos, if true move pointer up one
