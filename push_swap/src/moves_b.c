/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:08:51 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/20 17:14:38 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Calcula la cantidad de movimientos necesarios para colocar el elemento máximo
 * o minimo de la pila B en la posición correcta.
 *
 * @param stacks Puntero a la estructura que contiene las pilas y
 * los valores máximos (o minimos).
 */
void	max_min_in_b(t_stack *stacks)
{
	int	index;
	int	size;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	if (stacks->list_b->content == stacks->value->max_b)
		return ;
	index = find_index(stacks->list_b, stacks->value->max_b);
	size = stack_size(stacks->list_b);
	if (size % 2 == 0)
	{
		if (index + 1 > size / 2)
			stacks->moves->rrb = (size - index);
		else
			stacks->moves->rb = index;
	}
	else
	{
		if (index > size / 2)
			stacks->moves->rrb = (size - index);
		else
			stacks->moves->rb = index;
	}
}

/**
 * @brief Inserta un nuevo elemento en la pila B y calcula los movimientos
 * necesarios para hacerlo.
 * 
 * Esta función busca el número del elemento en la pila B y calcula los
 * movimientos necesarios para insertarlo en la posición correcta. Los 
 * movimientos se almacenan en la estructura `stacks->moves`,
 * en los campos `rb` y `rrb`.
 * 
 * @param stacks Puntero a la estructura `t_stack` que contiene las pilas 
 * A y B, así como los movimientos.
 * @param stack_a Puntero a la lista enlazada que contiene el elemento a
 * insertar en la pila B.
 */
void	new_elem_in_b(t_stack *stacks, t_linked_list *stack_a)
{
	int	index;
	int	search;
	int	size;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	search = search_number_in_b(stacks->list_b, stack_a->content);
	if (stacks->list_b->content == search)
		return ;
	index = find_index(stacks->list_b, search);
	size = stack_size(stacks->list_b);
	if (size % 2 == 0)
	{
		if (index + 1 > size / 2)
			stacks->moves->rrb = (size - index);
		else
			stacks->moves->rb = index;
	}
	else
	{
		if (index > size / 2)
			stacks->moves->rrb = size - index;
		else
			stacks->moves->rb = index;
	}
}

/**
 * Mueve el elemento en la posición especificada (i) en la pila A hacia 
 * la parte superior.
 * 
 * @param stacks Puntero a la estructura de datos que contiene las pilas
 * y los movimientos.
 * @param stack_a Puntero a la lista enlazada que representa la pila A.
 * @param i Índice del elemento en la pila A que se moverá a la parte superior.
 */
void	to_top_stack_a(t_stack *stacks, t_linked_list *stack_a, int i)
{
	int	size;

	stacks->moves->pb = 1;
	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->list_a->content == stack_a->content)
		return ;
	size = stack_size(stacks->list_a);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->moves->rra = (size - i);
		else
			stacks->moves->ra = i;
	}
	else
	{
		if (i > size / 2)
			stacks->moves->rra = size - i;
		else
			stacks->moves->ra = i;
	}
}
