/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:01:32 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/07 00:47:31 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "string.h"

void	check_add(t_node **stack_a, int ac, char **av)
{
	int		i;
	int		num;
	char	**strings;
	char	**strings_tmp;
	char	*check;

	check = ft_generate_argv(ac, av);
	i = 0;
	while (i < ac - 1)
	{
		if (!av[i][0])
		{
			printf("Error\n");
			exit(1);
		}
		strings_tmp = ft_split(av[i + 1], ' ');
		if (!strings_tmp)
		{
			free_strings(strings_tmp);
			return ;
		}
		strings = strings_tmp;
		while (*strings)
		{
			if (!is_valid_number(*strings))
			{
				printf("Error\n");
				free_strings(strings_tmp);
				exit(1);
			}
			num = ft_atoi(*strings);
			add_node_in_top(stack_a, num);
			strings++;
		}
		free_strings(strings_tmp);
		i++;
	}
	is_duplicates(stack_a);
}

int	is_valid_number(char *str)
{
	int	nb;
	int	int_min;
	int	int_max;
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
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
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

char	*ft_generate_argv(int ac, char **av)
{
	char	*str_join;
	char	*tmp;
	int		i;

	str_join = "";
	i = 1;
	while (i < ac)
	{
		if (!av[i][0])
		{
			printf("Error\n");
			exit(1);
		}
		tmp = ft_strjoin(str_join, av[i]);
		str_join = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	return (str_join);
}
