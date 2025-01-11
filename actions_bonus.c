/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <ayelasef@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:42:49 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/09 19:13:08 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_apply_actions_in_stack(t_node **stack_a, t_node **stack_b,
		char *line)
{
	if (!line)
		return ;
	if (!ft_strncmp("sa\n", line, 3))
		sa(stack_a);
	else if (!ft_strncmp("sb\n", line, 3))
		sb(stack_b);
	else if (!ft_strncmp("ss\n", line, 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp("pa\n", line, 3))
		push_a(stack_a, stack_b);
	else if (!ft_strncmp("pb\n", line, 3))
		push_b(stack_a, stack_b);
	else if (!ft_strncmp("ra\n", line, 3))
		ra(stack_a);
	else if (!ft_strncmp("rb\n", line, 3))
		rb(stack_a);
	else if (!ft_strncmp("rr\n", line, 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp("rra\n", line, 4))
		rra(stack_a);
	else if (!ft_strncmp("rrb\n", line, 4))
		rrb(stack_b);
	else if (!ft_strncmp("rrr\n", line, 4))
		rrr(stack_a, stack_b);
	else
		ft_perror();
}
