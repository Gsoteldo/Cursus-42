/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:04:33 by gsoteldo          #+#    #+#             */
/*   Updated: 2023/09/28 18:04:41 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
