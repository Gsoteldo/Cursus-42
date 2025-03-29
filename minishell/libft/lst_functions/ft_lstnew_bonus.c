/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:04:49 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/02/01 00:26:38 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Crea un nuevo nodo para una lista enlazada.
 * Asigna memoria dinámicamente para un nuevo nodo de la lista.
 * Asigna el puntero al contenido del nodo al contenido del nuevo nodo.
 * Asigna nulo al campo `next` del nuevo nodo.
 * Retorna el nuevo nodo.
 *
 * @param content: Puntero al contenido del nuevo nodo.
 * @return: El nuevo nodo.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)ft_calloc(1, sizeof(t_list));
	if (ptr == NULL)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
