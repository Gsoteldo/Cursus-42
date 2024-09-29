/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:45:34 by gsoteldo          #+#    #+#             */
/*   Updated: 2023/09/20 20:46:16 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == 0 || new == 0)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
int main()
{
    t_list *lst;
    t_list *new;

    lst = ft_lstnew("first");
    lst->next = ft_lstnew("second");
    lst->next->next = ft_lstnew("third");
    lst->next->next->next = ft_lstnew("fourth");
    lst->next->next->next->next = ft_lstnew("fifth");
    new = ft_lstnew("primera");
    ft_lstadd_front(&lst, new);
    while (lst)
    {
        printf("%s\n", (char *)lst->content);
        lst = lst->next;
    }
    return (0);
}
*/