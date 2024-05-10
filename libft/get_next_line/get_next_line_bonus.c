/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 09:59:14 by asfletch          #+#    #+#             */
/*   Updated: 2023/11/14 10:50:16 by asfletch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*store_for_next(char *stash)
{
	char	*result;
	char	*newline_ptr;
	size_t	i;

	i = 0;
	newline_ptr = ft_strchr(stash, '\n');
	if (newline_ptr == NULL)
	{
		free (stash);
		return (NULL);
	}
	newline_ptr++;
	result = ft_calloc((ft_strlen(newline_ptr) + 1), sizeof(char));
	if (result == NULL)
	{
		return (NULL);
	}
	while (newline_ptr[i])
	{
		result[i] = newline_ptr[i];
		i++;
	}
	result[i] = '\0';
	free (stash);
	return (result);
}

char	*create_result(char *stash)
{
	char	*result;
	size_t	i;
	size_t	alloc_size;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		alloc_size = i + 2;
	else
		alloc_size = i + 1;
	result = ft_calloc(alloc_size, sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		result[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		result[i] = '\n';
	return (result);
}

int	initialize_buffer_and_stash(char **stash, char **buffer)
{
	if (*stash == NULL)
	{
		*stash = ft_calloc(1, 1);
		if (*stash == NULL)
			return (0);
	}
	*buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (*buffer == NULL)
	{
		free (stash);
		free (*stash);
		*stash = NULL;
		return (0);
	}
	return (1);
}

char	*read_file(int fd, char *stash)
{
	char	*buffer;
	int		bytes_being_read;

	if (initialize_buffer_and_stash(&stash, &buffer) == 0)
	{
		free (stash);
		return (NULL);
	}
	bytes_being_read = 1;
	while (bytes_being_read > 0)
	{
		bytes_being_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_being_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes_being_read] = '\0';
		stash = join_strings(stash, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*result;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free (stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = read_file(fd, stash[fd]);
	if (stash[fd] == NULL || ft_strlen(stash[fd]) == 0)
	{
		if (stash[fd] != NULL)
		{
			free (stash[fd]);
			stash[fd] = NULL;
		}
		stash[fd] = NULL;
		return (NULL);
	}
	result = create_result(stash[fd]);
	stash[fd] = store_for_next(stash[fd]);
	return (result);
}
