/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:28:47 by gsoteldo          #+#    #+#             */
/*   Updated: 2023/09/18 18:25:17 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = NULL;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		{
			i++;
		}
		while (ft_strchr(set, s1[j - 1]) && (j > i))
		{
			j--;
		}
		ptr = (char *)malloc(sizeof(char) * (j - i + 1));
		if (ptr)
		{
			ft_strlcpy(ptr, &s1[i], (j - i + 1));
		}
	}
	return (ptr);
}
