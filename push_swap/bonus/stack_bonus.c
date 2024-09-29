/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:33:08 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/02/19 20:05:35 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Crea un nuevo nodo para una lista enlazada con el contenido dado.
 *
 * @param content El contenido que se almacenará en el nodo.
 * @return Un puntero al nodo recién creado, o NULL si falla
 * la asignación de memoria.
 */
t_linked_list	*ft_new_a_node(int content)
{
	t_linked_list	*ptr;

	ptr = (t_linked_list *)malloc(sizeof(t_linked_list));
	if (ptr == 0)
		return (0);
	ptr->content = content;
	ptr->next = 0;
	return (ptr);
}

/**
 * Crea una nueva lista enlazada a partir de los argumentos de línea de comandos.
 *
 * @param argc El número de argumentos de línea de comandos.
 * @param argv Los argumentos de línea de comandos.
 * @return Un puntero a la nueva lista enlazada.
 */
t_linked_list	*ft_new_a_list(int argc, char **argv)
{
	int				i;
	int				j;
	t_linked_list	*ptr;
	t_linked_list	*tmp;

	i = 1;
	j = 0;
	j = argc;
	ptr = ft_new_a_node(ft_atoi(argv[i]));
	tmp = ptr;
	while (++i < j)
	{
		tmp->next = ft_new_a_node(ft_atoi(argv[i]));
		tmp = tmp->next;
		tmp->next = NULL;
	}
	return (ptr);
}

/**
 * Muestra los elementos de una pila en orden de arriba a abajo.
 *
 * @param stack La pila a mostrar.
 */
void	show_stack(t_linked_list *stack)
{
	t_linked_list	*temp;

	temp = stack;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}
}

/**
 * Calcula el tamaño de una pila.
 *
 * @param lst La lista enlazada que representa la pila.
 * @return El tamaño de la pila.
 */
int	stack_size(t_linked_list *stack)
{
	int	i;

	i = 0;
	if (stack == 0)
		return (0);
	while (stack != 0)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

/*
t_linked_list	*ft_str_to_a_list(char **str)
{
	int				i;
	int				counter;
	t_linked_list	*ptr;
	t_linked_list	*tmp;

	i = 0;
	counter = 0;
	str = ft_split(str[1], ' ');
	comprobation(2, str, NULL);
	is_repeated(2, str);
	while (str[i] != NULL)
	{
		i++;
		counter++;
	}
	i = 0;
	ptr = ft_new_a_node(ft_atoi(str[i]));
	tmp = ptr;
	while (++i < counter)
	{
		tmp->next = ft_new_a_node(ft_atoi(str[i]));
		tmp = tmp->next;
		tmp->next = NULL;
	}
	return (ptr);
}*/