/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:41:52 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/09 00:44:16 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_strings(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

int	is_sorted(t_node *stack_a)
{
	t_node	*node;

	node = stack_a;
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

void	free_stack(t_node **stack)
{
	t_node	*curr;
	t_node	*next;

	curr = *stack;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*stack = NULL;
}

void	sort_stack(t_node **stack_a, t_node **stack_b, int *arr, int size)
{
	int	*arr_sorted;

	arr_sorted = NULL;
	arr = push_element_in_arr(stack_a, size);
	arr_sorted = sort_arr(arr, size);
	push_to_stack_b(stack_a, stack_b, arr_sorted, size);
	free(arr_sorted);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;
	int		*arr;

	if (ac == 1)
		exit(1);
	stack_a = NULL;
	stack_b = NULL;
	arr = NULL;
	check_add(&stack_a, ac, av);
	if (!is_sorted(stack_a))
	{
		size = ft_lstsize(stack_a);
		if (size > 5)
			sort_stack(&stack_a, &stack_b, arr, size);
		else
			ft_sort_small_elment(&stack_a, &stack_b, size);
	}
	free_stack(&stack_a);
	free(arr);
	return (0);
}
