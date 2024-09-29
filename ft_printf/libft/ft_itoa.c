/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:55:54 by gsoteldo          #+#    #+#             */
/*   Updated: 2023/09/27 19:44:07 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	contardigitos(int n)
{
	int	i;
	int	aux;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	aux = n;
	while (aux > 0)
	{
		aux = aux / 10;
		i++;
	}
	return (i);
}

static int	contarexp(int n)
{
	int	exp;
	int	digits;

	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (1000000000);
	digits = contardigitos(n);
	if (n < 0)
		digits--;
	exp = 1;
	while (--digits)
		exp = exp * 10;
	return (exp);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			exp;
	int			i;
	long int	aux;

	aux = (long int)n;
	exp = contarexp(n);
	i = 0;
	str = malloc(contardigitos(n) + 1);
	if (!(str))
		return (NULL);
	if (n < 0)
	{
		str[i++] = '-';
		aux = -aux;
	}
	while (exp > 0)
	{
		str[i++] = (aux / exp) + 48;
		aux = aux % exp;
		exp = exp / 10;
	}
	str[i] = '\0';
	return (str);
}
