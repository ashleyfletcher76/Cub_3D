/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:42:50 by asfletch          #+#    #+#             */
/*   Updated: 2024/04/28 12:37:12 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	count_words(const char *str, char delim)
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

static size_t	new_strlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	return (i);
}

static int	sub_split(char **arr, char **s, char c)
{
	size_t	word_len;

	while (**s == c)
		(*s)++;
	word_len = new_strlen(*s, c);
	*arr = (char *)malloc(word_len + 1);
	if (*arr == NULL)
		return (0);
	ft_memcpy(*arr, *s, word_len);
	(*arr)[word_len] = '\0';
	*s += word_len;
	return (1);
}

void	free_allocated(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char delim)
{
	char		**result;
	size_t		word_count;
	size_t		substring_count;
	char		*str_iterator;

	str_iterator = (char *)s;
	substring_count = 0;
	if (!s)
		return (NULL);
	word_count = count_words(s, delim);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (substring_count < word_count)
	{
		if (!sub_split(&result[substring_count], &str_iterator, delim))
		{
			free_allocated(result, substring_count);
			return (NULL);
		}
		substring_count++;
	}
	result[substring_count] = NULL;
	return (result);
}

//double pointer, points to array of pointers
//**s checks curr pos, if true move pointer up one
