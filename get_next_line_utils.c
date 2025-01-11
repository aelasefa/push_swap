/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:04:46 by ayelasef          #+#    #+#             */
/*   Updated: 2024/11/22 12:36:34 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
	{
		free(s);
		return (NULL);
	}
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_get_line(char *s1, char *s2)
{
	char*(arr);
	int (i), (j);
	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = ft_strdup_get_line("");
		if (!s1)
			return (NULL);
	}
	arr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!arr)
		return (free(s1), NULL);
	i = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		arr[i++] = s2[j++];
	arr[i] = '\0';
	free(s1);
	return (arr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup_get_line(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup_get_line(const char *s1)
{
	char	*dst_d;
	size_t	size;
	int		i;

	size = ft_strlen(s1);
	dst_d = malloc(sizeof(char) * size + 1);
	if (!dst_d)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dst_d[i] = s1[i];
		i++;
	}
	dst_d[i] = '\0';
	return (dst_d);
}
