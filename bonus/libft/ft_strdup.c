/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:29:11 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/07 09:14:52 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*dst_d;
	size_t	size;
	int		i;

	size = ft_strlen(s1);
	dst_d = malloc(sizeof(char) * size + 1);
	if (!dst_d)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		dst_d[i] = s1[i];
		i++;
	}
	dst_d[i] = '\0';
	return (dst_d);
}
