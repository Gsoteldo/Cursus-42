/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:00 by gsoteldo          #+#    #+#             */
/*   Updated: 2023/11/14 16:33:38 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

void	ft_printstring(char *str, int *total)
{
	int	aux;

	aux = 0;
	if (str == NULL)
	{
		aux = write(1, "(null)", 6);
		if (aux == -1)
		{
			*total = -1;
			return ;
		}
		*total = *total + 6;
		return ;
	}
	aux = write(1, str, ft_strlen(str));
	if (aux == -1)
	{
		*total = -1;
		return ;
	}
	*total = *total + ft_strlen(str);
}
