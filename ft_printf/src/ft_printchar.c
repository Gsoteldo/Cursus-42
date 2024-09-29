/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:11:25 by gsoteldo          #+#    #+#             */
/*   Updated: 2023/11/14 16:25:26 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printchar(int c, int *total)
{
	int	aux;

	aux = write(1, &c, 1);
	if (aux == -1)
	{
		*total = -1;
		return ;
	}
	*total = *total + aux;
}
