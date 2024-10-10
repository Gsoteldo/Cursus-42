/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:04:33 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:21:32 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Crea una nueva lista enlazada a partir de una existente, aplicando 
 * una función dada a cada elemento de la lista original.
 * Aplica la función de transformación al contenido del nodo actual 
 * de la lista original para obtener el contenido del nuevo nodo, crea 
 * un nuevo nodo con ese contenido y lo añade al final de la nueva lista.
 * Cuando la lista original esté vacía, retorna la nueva lista.
 *
 * @param lst: Puntero al primer nodo de la lista original.
 * @param f: Función de transformación a aplicar a cada elemento de la 
 * lista original.
 * @param del: Función de eliminación a llamar para cada elemento de la 
 * lista original cuando ya no sea necesario.
 * @return: Una nueva lista enlazada con los elementos transformados 
 * de la lista original.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*primera;
	t_list	*nuevo;

	if (f == 0 || del == 0)
		return (0);
	primera = 0;
	while (lst)
	{
		nuevo = ft_lstnew((*f)(lst->content));
		if (!nuevo)
		{
			while (primera)
			{
				nuevo = primera->next;
				(*del)(primera->content);
				free(primera);
				primera = nuevo;
			}
			lst = 0;
			return (0);
		}
		ft_lstadd_back(&primera, nuevo);
		lst = lst->next;
	}
	return (primera);
}
