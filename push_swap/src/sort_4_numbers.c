/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:43:47 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/19 18:46:26 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Ordena un conjunto de 4 números en una pila utilizando el algoritmo
 * push_swap.
 *
 * Esta función toma un puntero a una estructura de tipo t_stack que contiene 
 * dos pilas, list_a y list_b. Se asigna memoria para las estructuras t_moves y
 * t_value en la estructura t_stack. Luego, se realiza una operación push_b para
 * mover el primer número de la pila list_a a la pila list_b. A continuación,
 * se llama a la función sort_3_numbers para ordenar los tres números restantes
 * en la pila list_a. Después, se realizan movimientos en la pila list_a
 * utilizando la función moves_stack_a. Finalmente, se liberan las estructuras
 * de memoria asignadas y se realiza una limpieza adicional.
 *
 * @param stacks Puntero a la estructura t_stack que contiene las pilas list_a
 * y list_b.
 */
void	sort_4_numbers(t_stack *stacks)
{
	stacks->moves = (t_moves *)malloc(sizeof(t_moves));
	stacks->cheapest = (t_moves *)malloc(sizeof(t_moves));
	stacks->value = (t_value *)malloc(sizeof(t_value));
	push_b(&stacks->list_a, &stacks->list_b);
	sort_3_numbers(&stacks->list_a);
	moves_stack_a(stacks);
	free_stacks(stacks, 1, 0, 1);
}
