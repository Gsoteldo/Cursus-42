/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:33 by gsoteldo          #+#    #+#             */
/*   Updated: 2023/11/14 16:34:51 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printunsigned(unsigned int n, int *total)
{
	int	aux;

	if (n <= 9)
	{
		ft_printchar(n + '0', total);
		aux = *total;
		if (aux == -1)
		{
			*total = -1;
			return ;
		}
	}
	else
	{
		ft_printunsigned(n / 10, total);
		aux = *total;
		if (aux == -1)
		{
			*total = -1;
			return ;
		}
		ft_printchar(n % 10 + '0', total);
	}
}
