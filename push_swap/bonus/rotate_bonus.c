/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:59:32 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/21 16:46:10 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Realiza una rotación hacia arriba en una pila dada.
 *
 * @param stack Puntero al puntero de la pila.
 */
void	rotate(t_linked_list **stack)
{
	t_linked_list	*temp;
	t_linked_list	*temp2;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	temp2 = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = temp2;
	*stack = temp2->next;
	temp2->next = NULL;
}

/**
 * @brief Realiza una rotación hacia arriba en la pila A y muestra un mensaje.
 *
 * @param stack_a Puntero al puntero de la pila A.
 */
void	rotate_a(t_linked_list **stack_a)
{
	rotate(stack_a);
}

/**
 * @brief Realiza una rotación hacia arriba en la pila B y muestra un mensaje.
 *
 * @param stack_b Puntero al puntero de la pila B.
 */
void	rotate_b(t_linked_list **stack_b)
{
	rotate(stack_b);
}

/**
 * @brief Realiza una rotación hacia arriba en las pilas A y B y muestra
 * un mensaje.
 *
 * @param stack_a Puntero al puntero de la pila A.
 * @param stack_b Puntero al puntero de la pila B.
 */
void	rotate_ab(t_linked_list **stack_a, t_linked_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
