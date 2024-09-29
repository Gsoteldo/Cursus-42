/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:52:07 by gsoteldo          #+#    #+#             */
/*   Updated: 2023/09/27 19:44:56 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*ptr1;
	char		*ptr2;

	i = 0;
	if (!dst && !src)
		return (0);
	ptr1 = (char *)src;
	ptr2 = (char *)dst;
	while (i < n)
	{
		ptr2[i] = ptr1[i];
		i++;
	}
	return (dst);
}
