/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:01:32 by ayelasef          #+#    #+#             */
/*   Updated: 2024/12/28 17:48:45 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valide_number(char *str)
{
	int	nb;
	int	int_min;
	int	int_max;
	int	i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while(str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	int_min = -2147483648;
	int_max = 2147483647;
	nb = ft_atoi(str);
	if (nb < int_min || nb > int_max)
		return (0);
	return (1);
}

int	is_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_generate_argv(int ac, char **av)
{
	char	*str_join = "";
	char	*tmp;

	int	i;

	i = 1;
	while(i < ac)
	{
		tmp = ft_strjoin(str_join, av[i]);
		str_join = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	return (str_join);
}
