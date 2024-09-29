/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:08:32 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/21 16:42:07 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Libera la memoria ocupada por una lista enlazada.
 *
 * @param list Puntero al primer nodo de la lista enlazada.
 */
void	free_linked_list(t_linked_list *list)
{
	t_linked_list	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

/**
 * @brief Libera la memoria asignada a las estructuras de datos utilizadas en
 * el programa.
 * 
 * Esta función libera la memoria asignada a las estructuras de datos utilizadas
 * en el programa. Si el indicador stack_flag es igual a 1, se liberan las listas
 * enlazadas, los movimientos, los valores más baratos y los valores de las
 * pilas. Si el indicador error_flag es igual a 1, se imprime el mensaje de error
 * "Error\n". Si el indicador exit_flag es igual a 1, se llama a la función
 * exit(0).
 * 
 * @param stacks Puntero a la estructura de datos que contiene las pilas y otros 
 * elementos relacionados.
 * @param stack_flag Indicador para liberar las estructuras de datos de las
 * pilas.
 * @param error_flag Indicador para imprimir el mensaje de error.
 * @param exit_flag Indicador para llamar a la función exit(0).
 */
void	free_stacks(t_stack *stacks, int stackflag, int errorflag, int exitflag)
{
	if (stackflag == 1)
	{
		free_linked_list(stacks->list_a);
		free_linked_list(stacks->list_b);
		free(stacks->moves);
		free(stacks->cheapest);
		free(stacks->value);
	}
	if (errorflag == 1)
		ft_putstr_fd("Error\n", 2);
	if (exitflag == 1)
		exit(0);
}
