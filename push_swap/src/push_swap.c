/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:33:54 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/21 17:59:29 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Realiza el algoritmo de ordenamiento push_swap.
 * Primero, verifica si la pila ya está ordenada con la función "is_ordered".
 * 
 * Si la pila tiene un solo elemento, se libera la memoria y se termina 
 * la función.
 * 
 * Si la pila tiene dos elementos, se intercambian y luego se libera
 * la memoria.
 * 
 * Si la pila tiene tres elementos, se ordenan con la función "sort_3_numbers"
 * y luego se libera la memoria.
 * 
 * Si la pila tiene cuatro elementos, se ordenan con la función
 * "sort_4_numbers".
 * 
 * Si la pila tiene más de cuatro elementos, se mueven los dos primeros
 * elementos a la pila B, se realiza la operación más barata con la
 * función "cheapest", se ordenan los tres primeros números de la pila A,
 * finalmente se realizan movimientos en la pila A con la función
 * "moves_stack_a".
 * 
 * @param stacks Puntero a la estructura que contiene las pilas
 * 'list_a' y 'list_b'.
 */
void	push_swap(t_stack *stacks)
{
	is_ordered(stacks->list_a);
	if (stack_size(stacks->list_a) == 1)
		free_stacks(stacks, 1, 0, 1);
	else if (stack_size(stacks->list_a) == 2)
	{
		swap_a(&stacks->list_a);
		free_stacks(stacks, 1, 0, 1);
	}
	else if (stack_size(stacks->list_a) == 3)
	{
		sort_3_numbers(&stacks->list_a);
		free_stacks(stacks, 1, 0, 1);
	}
	else if (stack_size(stacks->list_a) == 4)
		sort_4_numbers(stacks);
	else
	{
		push_b(&stacks->list_a, &stacks->list_b);
		push_b(&stacks->list_a, &stacks->list_b);
		cheapest(stacks);
		sort_3_numbers(&stacks->list_a);
		moves_stack_a(stacks);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stacks;

	stacks = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (checker(argc, argv, stacks) == 0)
		return (0);
	stacks->list_a = ft_new_a_list(argc, argv);
	stacks->list_b = NULL;
	push_swap(stacks);
	free_stacks(stacks, 1, 0, 1);
	return (0);
}
