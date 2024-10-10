/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:02:03 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:20:34 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Añade un nuevo nodo a la cola de una lista enlazada.
 * Si la lista está vacía, establece el nuevo nodo como el primer nodo 
 * de la lista.
 * Si la lista no está vacía, establece el campo `next` del último nodo 
 * para apuntar al nuevo nodo.
 *
 * @param lst: Puntero a un puntero al primer nodo de la lista.
 * @param new: Puntero al nuevo nodo a añadir a la lista.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == 0 || new == 0)
		return ;
	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}
