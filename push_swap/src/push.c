/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:51:29 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/21 16:48:57 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Realiza la operación de empujar (push) un elemento desde una pila fuente
 * a una pila destino. Si la pila destino es nula, no se realiza ninguna
 * operación.
 *
 * @param source Puntero al puntero de la pila fuente.
 * @param destiny Puntero al puntero de la pila destino.
 */
void	push(t_linked_list **source, t_linked_list **destiny)
{
	t_linked_list	*temp;

	if (*source == NULL)
		return ;
	temp = (*source)->next;
	(*source)->next = *destiny;
	*destiny = *source;
	*source = temp;
}

/**
 * Realiza la operación de empujar (push) un elemento desde la pila B
 * a la pila A. Imprime "pa" después de realizar la operación.
 *
 * @param stack_a Puntero al puntero de la pila A.
 * @param stack_b Puntero al puntero de la pila B.
 */
void	push_a(t_linked_list **stack_a, t_linked_list **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

/**
 * Realiza la operación de empujar (push) un elemento desde la pila A
 * a la pila B. Imprime "pb" después de realizar la operación.
 *
 * @param stack_a Puntero al puntero de la pila A.
 * @param stack_b Puntero al puntero de la pila B.
 */
void	push_b(t_linked_list **stack_a, t_linked_list **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
