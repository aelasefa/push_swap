/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:11:21 by ayelasef          #+#    #+#             */
/*   Updated: 2024/11/05 16:00:25 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(int a)
{
	if (a < 0)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	result;
	int				signe;

	i = 0;
	signe = 1;
	result = 0;
	while ((str[i] != '\0' && str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (((result * 10) + (str[i] - '0')) > 9223372036854775807)
			return (check(signe));
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (signe * result);
}
