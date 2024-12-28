#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>
typedef struct s_node 
{
	int value;
	struct s_node *next;
}	t_node;

//check Error
int     is_valide_number(char *str);
int     is_duplicates(int *arr, int size);
char	*ft_generate_argv(int ac, char **av);


//stack operations
t_node *pop(t_node *stack);
void    push_a(t_node **stack_a, t_node **stack_b);
void    push_b(t_node **stack_a, t_node **stack_b);
void    swap(t_node **stack);
void    rotate(t_node **stack);
void    reverse_rotate(t_node   **stack);

//push swap_utils
void	add_node_in_top(t_node **stack, int value);

#endif
