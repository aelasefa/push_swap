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

#include "push_swap_bonus.h"

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

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d -> ", stack->value);
		stack = stack->next;
	}
	printf("NULL\n");
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

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	*line;

	stack_a = NULL;
	stack_b = NULL;
	line = get_next_line(0);
	check_add(&stack_a, ac, av);
	ft_apply_actions_in_stack(&stack_a, &stack_b, line);
	while (line)
	{
		if (is_sorted(stack_a) && stack_b == NULL)
		{
			write(1, "OK\n", 3);
			exit(0);
		}
		else
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		free(line);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
