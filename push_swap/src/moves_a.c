/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:02:30 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/20 20:12:36 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Realiza los movimientos necesarios en la pila A.
 * 
 * @param stacks Puntero a la estructura que contiene las pilas.
 * @param push_flag Bandera que indica si se debe realizar un push a la pila A.
 */
void	moves(t_stack *stacks, int push_flag)
{
	while (stacks->moves->ra-- != 0)
		rotate_a(&stacks->list_a);
	while (stacks->moves->rra-- != 0)
		r_rotate_a(&stacks->list_a);
	if (push_flag == 1)
		push_a(&stacks->list_a, &stacks->list_b);
}

/**
 * @brief Reordena la pila A para colocar el elemento mínimo en la parte
 * superior.
 *
 * Esta función calcula la cantidad de movimientos necesarios para
 * colocar el elemento mínimo de la pila A en la parte superior. Luego,
 * actualiza los contadores de movimientos en la estructura `stacks->moves`
 * y llama a la función `moves` para ejecutar los movimientos.
 *
 * @param stacks Puntero a la estructura `t_stack` que contiene las pilas y los
 * contadores de movimientos.
 * @param flag Carácter que indica el tipo de movimiento a realizar.
 */
void	new_order_min_stack(t_stack *stacks, char flag)
{
	int	index;
	int	size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	index = find_index(stacks->list_a, stacks->value->min_a);
	size = stack_size(stacks->list_a);
	if (stacks->list_a->content != stacks->value->min_a)
	{
		if (size % 2 == 0)
		{
			if (index + 1 > size / 2)
				stacks->moves->rra = size - index;
			else
				stacks->moves->ra = index;
		}
		else
		{
			if (index > size / 2)
				stacks->moves->rra = size - index;
			else
				stacks->moves->ra = index;
		}
	}
	moves(stacks, flag);
}

/**
 * @brief Reordena la pila A para colocar el elemento máximo en la
 * parte superior.
 * 
 * Esta función calcula la cantidad de movimientos necesarios para colocar el
 * elemento máximo de la pila A en la parte superior. Luego, actualiza los
 * contadores de movimientos en la estructura `stacks->moves` y llama a la
 * función `moves` para ejecutar los movimientos.
 * 
 * @param stacks Puntero a la estructura `t_stack` que contiene las pilas y los
 * contadores de movimientos.
 * @param flag Bandera que indica si se deben imprimir los movimientos
 * realizados.
 */
void	new_order_max_stack(t_stack *stacks, int flag)
{
	int	index;
	int	size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	index = find_index(stacks->list_a, stacks->value->max_a);
	size = stack_size(stacks->list_a);
	if (ft_last(stacks->list_a)->content != stacks->value->max_a)
	{
		if (size % 2 == 0)
		{
			if (index + 1 > size / 2)
				stacks->moves->rra = (size - index) - 1;
			else
				stacks->moves->ra = index + 1;
		}
		else
		{
			if (index > size / 2)
				stacks->moves->rra = (size - index) - 1;
			else
				stacks->moves->ra = index + 1;
		}
	}
	moves(stacks, flag);
}

/**
 * Función que realiza los movimientos necesarios en la pila A
 * para colocar un nuevo elemento en su posición correcta.
 *
 * @param stacks Puntero a la estructura que contiene las pilas A y B.
 * @param num Puntero a la lista enlazada que representa la pila B.
 */
void	new_elem_in_a(t_stack *stacks, int num)
{
	int	index;
	int	search;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	search = search_number_in_a(stacks->list_a, num);
	index = find_index(stacks->list_a, search);
	if (stacks->list_a->content != search)
	{
		if (stack_size(stacks->list_a) % 2 == 0)
		{
			if (index + 1 > stack_size(stacks->list_a) / 2)
				stacks->moves->rra = (stack_size(stacks->list_a) - index);
			else
				stacks->moves->ra = index;
		}
		else
		{
			if (index > stack_size(stacks->list_a) / 2)
				stacks->moves->rra = stack_size(stacks->list_a) - index;
			else
				stacks->moves->ra = index;
		}
	}
	moves(stacks, 1);
}

/**
 * Realiza movimientos en la pila A.
 *
 * Esta función realiza una serie de movimientos en la pila A
 * basados en las condiciones establecidas en el código.
 * Los movimientos incluyen reordenar la pila A, agregar nuevos elementos
 * y rotar la pila A.
 *
 * @param stacks Un puntero a la estructura de datos que contiene las pilas.
 */
void	moves_stack_a(t_stack *stacks)
{
	while (stacks->list_b != 0)
	{
		is_max_min(stacks, 1, 1);
		if (stacks->list_b->content < stacks->value->min_a)
			new_order_min_stack(stacks, 1);
		else if (stacks->list_b->content > stacks->value->max_a)
		{
			new_order_max_stack(stacks, 1);
			rotate_a(&stacks->list_a);
		}
		else
			new_elem_in_a(stacks, stacks->list_b->content);
	}
	is_max_min(stacks, 1, 0);
	new_order_min_stack(stacks, 0);
}
