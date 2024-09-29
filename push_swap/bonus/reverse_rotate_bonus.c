/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:59:36 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/21 16:45:39 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Realiza una rotación hacia arriba en una pila enlazada.
 *
 * @param stack Puntero al puntero de la pila enlazada.
 */
void	r_rotate(t_linked_list **stack)
{
	t_linked_list	*temp;
	t_linked_list	*temp2;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	temp2 = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp2 = temp->next;
	temp->next = NULL;
	temp2->next = *stack;
	*stack = temp2;
}

/**
 * Realiza una rotación hacia arriba en la pila A.
 * 
 * @param stack_a Puntero a la pila A.
 */
void	r_rotate_a(t_linked_list **stack_a)
{
	r_rotate(stack_a);
}

/**
 * Realiza una rotación hacia arriba en la pila B.
 * 
 * @param stack_b Puntero a la pila B.
 */
void	r_rotate_b(t_linked_list **stack_b)
{
	r_rotate(stack_b);
}

/**
 * Realiza una rotación hacia arriba en las pilas A y B al mismo tiempo.
 * 
 * @param stack_a Puntero a la pila A.
 * @param stack_b Puntero a la pila B.
 */
void	r_rotate_ab(t_linked_list **stack_a, t_linked_list **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
}
