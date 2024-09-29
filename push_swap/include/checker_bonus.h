/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:52:08 by gabo              #+#    #+#             */
/*   Updated: 2024/02/20 20:01:42 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"

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

void			free_stacks(t_stack *stacks, int stackflag, \
				int errorflag, int exitflag);

void			push(t_linked_list **source, t_linked_list **destiny);
void			push_a(t_linked_list **stack_a, t_linked_list **stack_b);
void			push_b(t_linked_list **stack_a, t_linked_list **stack_b);

void			r_rotate(t_linked_list **stack);
void			r_rotate_a(t_linked_list **stack_a);
void			r_rotate_b(t_linked_list **stack_b);
void			r_rotate_ab(t_linked_list **stack_a, t_linked_list **stack_b);

void			rotate(t_linked_list **stack);
void			rotate_a(t_linked_list **stack_a);
void			rotate_b(t_linked_list **stack_b);
void			rotate_ab(t_linked_list **stack_a, t_linked_list **stack_b);

void			swap(t_linked_list **stack);
void			swap_a(t_linked_list **stack_a);
void			swap_b(t_linked_list **stack_b);
void			swap_ab(t_linked_list **stack_a, t_linked_list **stack_b);

t_linked_list	*ft_new_a_node(int content);
t_linked_list	*ft_new_a_list(int argc, char **argv);
void			show_stack(t_linked_list *stack);
int				stack_size(t_linked_list *stack);

int				checker(int argc, char **argv, t_stack *stacks);

#endif