/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:02:53 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:20:50 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Borra todos los nodos de una lista enlazada llamando a una función de 
 * eliminación pasada como argumento.
 * Mientras la lista no esté vacía, guarda el siguiente nodo en una 
 * variable temporal, llama a la función de eliminación para eliminar 
 * el nodo actual, y luego actualiza el puntero a la lista al siguiente nodo.
 *
 * @param lst: Puntero a un puntero al primer nodo de la lista.
 * @param del: Función de eliminación a llamar para cada nodo de la lista.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == 0 || del == 0)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
