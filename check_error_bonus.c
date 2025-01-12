/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:01:32 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/07 09:13:00 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_add(t_node **stack_a, int ac, char **av)
{
	char	**strings;
	char	**strings_tmp;
	long	num;
	int		i;

	i = 0;
	while (i < ac - 1)
	{
		num = ft_atoi(av[i + 1]);
		if (!av[i + 1][0] || num > 2147483647 || num < -2147483648)
			ft_perror(stack_a);
		strings_tmp = ft_split(av[i + 1], ' ');
		if (!strings_tmp)
		{
			free_strings(strings_tmp);
			return ;
		}
		strings = strings_tmp;
		clean_input_in_stack(stack_a, strings, strings_tmp);
		free_strings(strings_tmp);
		i++;
	}
	is_duplicates(stack_a);
}

void	clean_input_in_stack(t_node **stack_a, char **strings,
		char **strings_tmp)
{
	int	num;
	int	i;

	i = 0;
	while (strings[i])
	{
		if (!is_valid_number(strings[i]))
		{
			write(2, "Error\n", 6);
			free_stack(stack_a);
			free_strings(strings_tmp);
			exit(1);
		}
		num = ft_atoi(strings[i]);
		add_node_in_top(stack_a, num);
		i++;
	}
}

int	is_valid_number(char *str)
{
	long	nb;
	int		int_min;
	int		int_max;
	int		i;

	i = 0;
	int_min = -2147483648;
	int_max = 2147483647;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		nb = ft_atoi(str);
		if (!ft_isdigit(str[i]) || (nb < int_min || nb > int_max))
			return (0);
		i++;
	}
	return (1);
}

void	is_duplicates(t_node **stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = *stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp2->value == tmp->value)
				ft_perror(stack);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
