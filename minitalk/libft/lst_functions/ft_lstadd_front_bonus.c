/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:02:25 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:20:39 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Añade un nuevo nodo al principio de una lista enlazada.
 * Establece el campo `next` del nuevo nodo para apuntar al primer nodo 
 * de la lista.
 * Establece el primer nodo de la lista como el nuevo nodo.
 *
 * @param lst: Puntero a un puntero al primer nodo de la lista.
 * @param new: Puntero al nuevo nodo a añadir al principio de la lista.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == 0 || new == 0)
		return ;
	new->next = *lst;
	*lst = new;
}
