/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printinteger.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:13:51 by gsoteldo          #+#    #+#             */
/*   Updated: 2023/11/14 16:28:54 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	min_negative(int *total)
{
	int	numchar;
	int	aux;

	numchar = 0;
	ft_printchar('-', total);
	aux = *total;
	if (aux == -1)
		return (-1);
	numchar = numchar + aux;
	aux = 0;
	ft_printstring("2147483648", total);
	numchar = numchar + aux;
	return (numchar);
}

static int	negative_numbers(int n, int *total)
{
	int	aux;
	int	numchar;

	aux = 0;
	numchar = 0;
	ft_printchar('-', total);
	aux = *total;
	if (aux == -1)
		return (-1);
	numchar = numchar + aux;
	aux = 0;
	ft_printinteger(n, total);
	aux = *total;
	if (aux == -1)
		return (-1);
	numchar = numchar + aux;
	return (numchar);
}

static int	other_cases(int n, int *total)
{
	int	aux;
	int	numchar;

	aux = 0;
	numchar = 0;
	ft_printinteger(n / 10, total);
	aux = *total;
	if (aux == -1)
		return (-1);
	numchar = numchar + aux;
	aux = 0;
	ft_printchar(48 + (n % 10), total);
	aux = *total;
	if (aux == -1)
		return (-1);
	numchar = numchar + aux;
	return (numchar);
}

void	ft_printinteger(int n, int *total)
{
	int	numchar;
	int	aux;

	numchar = 0;
	aux = 0;
	if (n == -2147483648)
	{
		n = -n;
		numchar += min_negative(total);
	}
	else if (n < 0)
	{
		n = -n;
		numchar += negative_numbers(n, total);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_printchar(n + '0', total);
		numchar = numchar + aux;
	}
	else
		numchar += other_cases(n, total);
}
