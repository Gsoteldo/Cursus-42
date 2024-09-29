/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:03:32 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:21:01 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Aplica una función dada a cada elemento de una lista enlazada.
 * Mientras la lista no esté vacía, aplica la función al contenido del 
 * nodo actual y luego pasa al siguiente nodo.
 *
 * @param lst: Puntero al primer nodo de la lista.
 * @param f: Función a aplicar a cada elemento de la lista.
 */
void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
