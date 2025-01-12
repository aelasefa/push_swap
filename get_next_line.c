/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:23:31 by ayelasef          #+#    #+#             */
/*   Updated: 2024/11/22 17:23:22 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_read(int fd, char *storage)
{
	char	*buff;
	int		read_ptr;

	read_ptr = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
	{
		free(storage);
		return (NULL);
	}
	while ((!storage || !ft_strchr(storage, '\n')) && read_ptr != 0)
	{
		read_ptr = read(fd, buff, BUFFER_SIZE);
		if (read_ptr == -1)
		{
			free(storage);
			free(buff);
			return (NULL);
		}
		buff[read_ptr] = '\0';
		storage = ft_strjoin_get_line(storage, buff);
	}
	free(buff);
	return (storage);
}

static char	*ft_line(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	if (storage[i] == '\n')
		i++;
	line = ft_substr(storage, 0, i);
	return (line);
}

static char	*ft_next_line(char *storage)
{
	char	*cpy;
	int		i;
	int		j;

	i = 0;
	while (storage[i] != '\n' && storage[i])
		i++;
	if (!storage[i])
		return (free(storage), NULL);
	i++;
	cpy = malloc(ft_strlen(storage) - i + 1);
	if (!cpy)
	{
		free(storage);
		return (NULL);
	}
	j = 0;
	while (storage[i])
		cpy[j++] = storage[i++];
	cpy[j] = '\0';
	free(storage);
	storage = NULL;
	return (cpy);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
	{
		free(storage);
		return (storage = NULL);
	}
	storage = ft_read(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_line(storage);
	storage = ft_next_line(storage);
	return (line);
}
