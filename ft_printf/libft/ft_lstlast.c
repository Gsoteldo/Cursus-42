/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:42:54 by gsoteldo          #+#    #+#             */
/*   Updated: 2023/09/20 20:44:30 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}
/*
int main()
{
    t_list *lst;
    t_list *last;

    lst = ft_lstnew("first");
    lst->next = ft_lstnew("second");
    lst->next->next = ft_lstnew("third");
    lst->next->next->next = ft_lstnew("fourth");
    lst->next->next->next->next = ft_lstnew("fifth");
    last = ft_lstlast(lst);
    printf("%s\n", (char *)last->content);
    return (0);
}
*/