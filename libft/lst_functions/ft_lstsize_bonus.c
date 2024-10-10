/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:05:07 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:21:43 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Calcula el tamaño de una lista enlazada, es decir, el número de nodos 
 * en la lista.
 * Pasa al siguiente nodo y aumenta el contador en 1 mientras la lista 
 * no esté vacía.
 * Cuando la lista esté vacía, retorna el contador, que es el tamaño de 
 * la lista.
 *
 * @param lst: Puntero al primer nodo de la lista.
 * @return: El tamaño de la lista.
 */
int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	if (lst == 0)
		return (0);
	while (lst != 0)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
