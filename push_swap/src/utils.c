/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:32:46 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/21 18:00:28 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Comprueba si una lista enlazada está ordenada de forma ascendente.
 *
 * @param stack_a La lista enlazada a comprobar.
 */
void	is_ordered(t_linked_list *stack_a)
{
	t_linked_list	*temp;

	temp = stack_a;
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return ;
		temp = temp->next;
	}
	exit(0);
}

/**
 * Encuentra el índice de un valor en una pila enlazada.
 *
 * @param stack La pila enlazada en la que se buscará el valor.
 * @param value El valor que se desea encontrar.
 * @return El índice del valor en la pila, o el tamaño de la pila
 * si no se encuentra.
 */
int	find_index(t_linked_list *stack, int value)
{
	t_linked_list	*temp;
	int				i;
	int				size;

	i = 0;
	temp = stack;
	size = stack_size(stack);
	while (i < size)
	{
		if (temp->content == value)
			return (i);
		temp = temp->next;
		i++;
	}
	return (i);
}

/**
 * Busca un número en la pila A.
 *
 * Esta función busca un número específico en la pila A y 
 * devuelve el siguiente número más grande si el número buscado 
 * no se encuentra en la pila.
 *
 * @param stack La pila A.
 * @param value El número a buscar.
 * @return El siguiente número más grande si el número buscado
 * no se encuentra en la pila.
 */
int	search_number_in_a(t_linked_list *stack, int value)
{
	t_linked_list	*temp;
	int				flag;
	int				i;
	int				size;

	i = 0;
	flag = 0;
	temp = stack;
	size = stack_size(stack);
	while (flag == 0)
	{
		i = 0;
		temp = stack;
		value++;
		while (i++ < size)
		{
			if (temp->content == value)
				flag = 1;
			temp = temp->next;
		}
	}
	return (value);
}

/**
 * Busca un número en la pila B.
 *
 * Esta función busca un número específico en la pila B y devuelve el valor
 * encontrado. Utiliza una estrategia de decrementar el valor y recorrer la pila
 * hasta encontrar una coincidencia.
 *
 * @param stack La pila en la que se realizará la búsqueda.
 * @param value El número que se desea buscar.
 * @return El valor encontrado en la pila B.
 */
int	search_number_in_b(t_linked_list *stack, int value)
{
	t_linked_list	*temp;
	int				flag;
	int				i;
	int				size;

	i = 0;
	flag = 0;
	temp = stack;
	size = stack_size(stack);
	while (flag == 0)
	{
		i = 0;
		temp = stack;
		value--;
		while (i++ < size)
		{
			if (temp->content == value)
				flag = 1;
			temp = temp->next;
		}
	}
	return (value);
}

/**
 * Obtiene el último elemento de una lista enlazada.
 *
 * @param stack Puntero al primer elemento de la lista.
 * @return Puntero al último elemento de la lista, o NULL si la lista está vacía.
 */
t_linked_list	*ft_last(t_linked_list *stack)
{
	if (stack == 0)
		return (0);
	while (stack->next != 0)
		stack = stack->next;
	return (stack);
}
