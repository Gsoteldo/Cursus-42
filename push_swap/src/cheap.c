/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:28:01 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/20 17:20:54 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Mueve los elementos más baratos de la pila.
 *
 * Esta función mueve los elementos más baratos de la pila según los valores
 * almacenados en la estructura `stack->cheapest`. Los elementos se mueven
 * utilizando las funciones `rotate_a`, `rotate_b`, `rotate_ab`, `r_rotate_a`,
 * `r_rotate_b`, `r_rotate_ab` y `push_b`.
 *
 * @param stack Puntero a la estructura `t_stack` que contiene las pilas.
 */
void	move_cheapest(t_stack *stack)
{
	while (stack->cheapest->ra-- != 0)
		rotate_a(&stack->list_a);
	while (stack->cheapest->rb-- != 0)
		rotate_b(&stack->list_b);
	while (stack->cheapest->rr-- != 0)
		rotate_ab(&stack->list_a, &stack->list_b);
	while (stack->cheapest->rra-- != 0)
		r_rotate_a(&stack->list_a);
	while (stack->cheapest->rrb-- != 0)
		r_rotate_b(&stack->list_b);
	while (stack->cheapest->rrr-- != 0)
		r_rotate_ab(&stack->list_a, &stack->list_b);
	while (stack->cheapest->pb-- != 0)
		push_b(&stack->list_a, &stack->list_b);
}

/**
 * Función para verificar los movimientos dobles.
 * Esta función actualiza los contadores de movimientos para los movimientos
 * ra, rb, rr, rra y rrb en la estructura de datos stacks.
 *
 * @param stacks Puntero a la estructura de datos que contiene las pilas y
 * los contadores de movimientos.
 */
void	double_moves_checker(t_stack *stacks)
{
	stacks->moves->rr = 0;
	stacks->moves->rrr = 0;
	while (stacks->moves->ra != 0 && stacks->moves->rb != 0)
	{
		stacks->moves->ra--;
		stacks->moves->rb--;
		stacks->moves->rr++;
	}
	while (stacks->moves->rra != 0 && stacks->moves->rrb != 0)
	{
		stacks->moves->rra--;
		stacks->moves->rrb--;
		stacks->moves->rrr++;
	}
}

/**
 * Calcula el costo de los movimientos y actualiza el movimiento más barato.
 * 
 * @param stacks Puntero a la estructura de pilas.
 * @param i Indicador de si es el primer movimiento o no.
 */
void	cost(t_stack *stacks, int i)
{
	stacks->moves->moves = stacks->moves->ra + stacks->moves->rb
		+ stacks->moves->rr + stacks->moves->rra + stacks->moves->rrb
		+ stacks->moves->rrr + stacks->moves->pb;
	if (i == 1 || stacks->moves->moves < stacks->cheapest->moves)
	{
		stacks->cheapest->moves = stacks->moves->moves;
		stacks->cheapest->ra = stacks->moves->ra;
		stacks->cheapest->rb = stacks->moves->rb;
		stacks->cheapest->rr = stacks->moves->rr;
		stacks->cheapest->rra = stacks->moves->rra;
		stacks->cheapest->rrb = stacks->moves->rrb;
		stacks->cheapest->rrr = stacks->moves->rrr;
		stacks->cheapest->pb = stacks->moves->pb;
	}
}

/**
 * Mueve los elementos del stack A a través de diferentes operaciones,
 * evaluando si es necesario mover elementos al stack B.
 *
 * @param stacks Puntero a la estructura que contiene los stacks.
 */
void	move_checker(t_stack *stacks)
{
	t_linked_list	*aux;
	int				i;
	int				size;

	aux = stacks->list_a;
	size = stack_size(stacks->list_a);
	i = 0;
	while (i++ < size)
	{
		to_top_stack_a(stacks, aux, i - 1);
		if (aux->content > stacks->value->max_b
			|| aux->content < stacks->value->min_b)
			max_min_in_b(stacks);
		else
			new_elem_in_b(stacks, aux);
		double_moves_checker(stacks);
		cost(stacks, i);
		aux = aux->next;
	}
}

/**
 * @brief Calcula la secuencia de movimientos más económica para 
 * ordenar la pila.
 * 
 * Esta función asigna memoria para las estructuras de movimientos
 * y valores, y luego realiza una serie de movimientos para encontrar
 * la secuencia más económica para ordenar la pila. La función se
 * detiene cuando el tamaño de la pila es igual a 3.
 * 
 * @param stacks Puntero a la estructura de pilas.
 */
void	cheapest(t_stack *stacks)
{
	stacks->moves = (t_moves *)ft_calloc(1, sizeof(t_moves));
	stacks->cheapest = (t_moves *)ft_calloc(1, sizeof(t_moves));
	stacks->value = (t_value *)ft_calloc(1, sizeof(t_value));
	while (stack_size(stacks->list_a) != 3)
	{
		is_max_min(stacks, 0, 1);
		move_checker(stacks);
		move_cheapest(stacks);
	}
}
