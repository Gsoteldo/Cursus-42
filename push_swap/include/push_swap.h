/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:40:43 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/20 19:55:13 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct t_linked_list
{
	int						content;
	struct t_linked_list	*next;
}	t_linked_list;

typedef struct t_stack
{
	struct t_linked_list	*list_a;
	struct t_linked_list	*list_b;
	struct t_moves			*cheapest;
	struct t_moves			*moves;
	struct t_value			*value;
}	t_stack;

typedef struct t_value
{
	int				max_a;
	int				max_b;
	int				min_a;
	int				min_b;
}	t_value;

typedef struct t_moves
{
	int	moves;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;	
	int	sa;
	int	sb;
	int	ss;
}	t_moves;

//checker
int				checker(int argc, char **argv, t_stack *stacks);
void			is_ordered(t_linked_list *stack_a);
void			comprobation(int argc, char **argv, t_stack *stacks);
int				is_repeated(int argc, char **argv);

//Stack_a
int				stack_size(t_linked_list *lst);
t_linked_list	*ft_last(t_linked_list *stack);
t_linked_list	*ft_new_a_list(int argc, char **argv);
t_linked_list	*ft_new_a_node(int content);
void			free_stacks(t_stack *stacks, int stackflag, \
					int errorflag, int exitflag);

void			is_max_min(t_stack *stacks, int flag_a, int flag_b);
void			show_stack(t_linked_list *stack);
void			moves_stack_a(t_stack *stacks);
void			to_top_stack_a(t_stack *stacks, t_linked_list *stack_a, int i);
int				search_number_in_a(t_linked_list *stack, int value);

//Stack_b
int				search_number_in_b(t_linked_list *stack, int value);
void			max_min_in_b(t_stack *stacks);
void			new_elem_in_b(t_stack *stacks, t_linked_list *stack_a);

//Push moves
void			push(t_linked_list **source, t_linked_list **destiny);
void			push_a(t_linked_list **stack_a, t_linked_list **stack_b);
void			push_b(t_linked_list **stack_a, t_linked_list **stack_b);

//Swap moves
void			swap(t_linked_list **stack);
void			swap_a(t_linked_list **stack_a);
void			swap_b(t_linked_list **stack_b);
void			swap_ab(t_linked_list **stack_a, t_linked_list **stack_b);

//Rotate moves
void			rotate_a(t_linked_list **stack_a);
void			rotate_ab(t_linked_list **stack_a, t_linked_list **stack_b);
void			rotate_b(t_linked_list **stack_b);
void			rotate(t_linked_list **stack);

//Reverse rotate moves
void			r_rotate(t_linked_list **stack);
void			r_rotate_a(t_linked_list **stack_a);
void			r_rotate_b(t_linked_list **stack_b);
void			r_rotate_ab(t_linked_list **stack_a, t_linked_list **stack_b);

//Sortings
void			sort_3_numbers(t_linked_list **stack_a);
void			sort_4_numbers(t_stack *stacks);

void			cheapest(t_stack *stacks);
int				find_index(t_linked_list *stack, int value);

#endif