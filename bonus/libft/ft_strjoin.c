/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:34:29 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/07 06:24:20 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *arr, char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	size_t	j;
	size_t	i;

	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (NULL);
	}
	if (!s2)
		return (NULL);
	arr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!arr)
		return (free(s1), NULL);
	arr = ft_strcpy(arr, s1);
	i = ft_strlen(arr);
	j = 0;
	while (s2[j])
		arr[i++] = s2[j++];
	arr[i] = ' ';
	arr[i + 1] = '\0';
	free(s1);
	free(s2);
	return (arr);
}
