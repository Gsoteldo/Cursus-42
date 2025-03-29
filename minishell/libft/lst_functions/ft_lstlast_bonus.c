/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:03:53 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:21:12 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Devuelve el último nodo de una lista enlazada.
 * Mientras haya un siguiente nodo en la lista, avanza al siguiente nodo.
 * Cuando ya no haya un siguiente nodo, retorna el nodo actual, que es el 
 * último nodo de la lista.
 *
 * @param lst: Puntero al primer nodo de la lista.
 * @return: El último nodo de la lista.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
