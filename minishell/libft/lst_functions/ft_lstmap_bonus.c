/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:04:33 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/09/07 14:46:33 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Crea una nueva lista a partir de una lista existente, aplicando una función
 * a cada elemento. Itera sobre la lista `lst`, aplica la función `f` a cada
 * elemento para crear un nuevo contenido, y crea una nueva lista con estos
 * elementos. Si se produce un error en la creación de un nuevo
 * elemento, limpia la lista creada y llama a la función `del` en el contenido
 * de los elementos fallidos.
 *
 * @param lst: Lista de entrada cuyos elementos serán mapeados.
 * @param f: Función que toma un puntero al contenido de un elemento y devuelve 
 * un nuevo contenido.
 * @param del: Función para liberar la memoria del contenido de los elementos
 * en caso de error.
 * @return Un puntero a la nueva lista con los elementos transformados.
 * Retorna NULL si ocurre un error.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	void	*content_temp;

	temp = NULL;
	new = NULL;
	if (f == NULL || del == NULL)
		return (NULL);
	while (lst != NULL)
	{
		content_temp = f(lst->content);
		temp = ft_lstnew(content_temp);
		if (temp == NULL)
		{
			del(content_temp);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
