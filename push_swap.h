/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:36:44 by ayelasef          #+#    #+#             */
/*   Updated: 2025/01/07 01:32:15 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

// check Error
int					is_valid_number(char *str);
void				is_duplicates(t_node **stack);
char				*ft_generate_argv(int ac, char **av);
void				check_add(t_node **stack_a, int ac, char **av);
void    clean_input_in_stack(t_node **stack_a, char **strings, char **strings_tmp);
int					ft_lstsize(t_node *lst);
// stack operations
t_node				*pop(t_node *stack);
void				push_a(t_node **stack_a, t_node **stack_b);
void				push_b(t_node **stack_a, t_node **stack_b);
void				sa(t_node **stack);
void				sb(t_node **stack);
void				ss(t_node **stack);
void				ra(t_node **stack);
void				rb(t_node **stack);
void				rr(t_node **stack);
void				rra(t_node **stack);
void				rrb(t_node **stack);
void				rrr(t_node **stack);

// push swap_utils
void				add_node_in_top(t_node **stack, int value);
// sort_stack
int					ft_is_small(t_node *stack, int *arr, int index);
int					*push_element_in_arr(t_node **stack_a, int size);
int					*sort_arr(int *arr, int size);
void				push_to_stack_b(t_node **stack_a, t_node **stack_b,
						int *arr, int size);
void				push_back_to_stack_a(t_node **stack_a, t_node **stack_b);
int					find_max_value(t_node *stack_b);

// sort_array
int					*push_element_in_arr(t_node **stack_a, int size);
int					*sort_arr(int *arr, int size);
// main
void				free_strings(char **strings);
void				print_stack(t_node *stack);

#endif
