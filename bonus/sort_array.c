/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:35:24 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/07 00:35:35 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	*push_element_in_arr(t_node **stack_a, int size)
{
	t_node	*node;
	int		*arr;
	int		i;

	node = *stack_a;
	arr = malloc(sizeof(int) * size);
	if (!arr)
	{
		free(arr);
		return (0);
	}
	i = 0;
	while (node)
	{
		arr[i] = node->value;
		node = node->next;
		i++;
	}
	return (arr);
}

int	*sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}
