/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:03:12 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/06 20:11:29 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Elimina un solo nodo de una lista enlazada.
 * Llama a la función de eliminación para el contenido del nodo.
 * Libera la memoria asignada al nodo.
 *
 * @param lst: Puntero al nodo de la lista a eliminar.
 * @param del: Función de eliminación a llamar para el contenido del nodo.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == 0 || del == 0)
		return ;
	del(lst->content);
	free(lst);
}
