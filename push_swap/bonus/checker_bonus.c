/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:37:36 by gabo              #+#    #+#             */
/*   Updated: 2024/02/20 21:24:38 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

/**
 * Verifica si una lista enlazada está ordenada en orden ascendente.
 *
 * @param stack_a Puntero a la lista enlazada.
 * @return 1 si la lista está ordenada, 0 en caso contrario.
 */
static int	is_ordered(t_linked_list *stack_a)
{
	t_linked_list	*temp;

	temp = stack_a;
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

/**
 * Realiza las operaciones correspondientes según la línea proporcionada.
 *
 * @param stacks Puntero a la estructura de pilas.
 * @param line Cadena que representa la operación a realizar.
 */
void	movements(t_stack *stacks, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap_a(&stacks->list_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap_b(&stacks->list_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		swap_ab(&stacks->list_a, &stacks->list_b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push_a(&stacks->list_a, &stacks->list_b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push_b(&stacks->list_a, &stacks->list_b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate_a(&stacks->list_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate_b(&stacks->list_b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rotate_ab(&stacks->list_a, &stacks->list_b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		r_rotate_a(&stacks->list_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		r_rotate_b(&stacks->list_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		r_rotate_ab(&stacks->list_a, &stacks->list_b);
	else
		free_stacks(stacks, 1, 1, 1);
}

/**
 * @brief Lee las instrucciones de entrada y realiza los movimientos
 * correspondientes en las pilas. Al finalizar, verifica si la pila A
 * está ordenada y si la pila B está vacía. Imprime "OK" si ambas
 * condiciones se cumplen, de lo contrario, imprime "KO".
 * 
 * @param stacks Estructura que contiene las pilas A y B.
 */
void	read_instructions(t_stack *stacks)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		movements(stacks, line);
		free(line);
	}
	if (stack_size(stacks->list_b) == 0 && is_ordered(stacks->list_a) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;

	stacks = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (checker(argc, argv, stacks) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	stacks->list_a = ft_new_a_list(argc, argv);
	stacks->list_b = NULL;
	read_instructions(stacks);
	free_stacks(stacks, 1, 0, 0);
	return (0);
}
