/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:03:32 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/09/07 14:47:29 by pmendez-         ###   ########.fr       */
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
	t_list	*aux;

	if (!f)
		return ;
	aux = lst;
	while (aux != NULL)
	{
		f(aux->content);
		aux = aux->next;
	}
}
