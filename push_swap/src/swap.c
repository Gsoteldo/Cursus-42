/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:59:26 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/21 16:49:55 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Intercambia los dos primeros elementos de una pila.
 * 
 * @param stack Un puntero al puntero de la pila.
 */
void	swap(t_linked_list **stack)
{
	t_linked_list	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

/**
 * Intercambia los dos primeros elementos de la pila A y muestra un mensaje.
 * 
 * @param stack_a Un puntero al puntero de la pila A.
 */
void	swap_a(t_linked_list **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

/**
 * Intercambia los dos primeros elementos de la pila B y muestra un mensaje.
 * 
 * @param stack_b Un puntero al puntero de la pila B.
 */
void	swap_b(t_linked_list **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

/**
 * Intercambia los dos primeros elementos de las pilas A y B 
 * y muestra un mensaje.
 * 
 * @param stack_a Un puntero al puntero de la pila A.
 * @param stack_b Un puntero al puntero de la pila B.
 */
void	swap_ab(t_linked_list **stack_a, t_linked_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
