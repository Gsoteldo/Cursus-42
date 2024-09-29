/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:11:52 by gsoteldo          #+#    #+#             */
/*   Updated: 2023/11/14 16:26:46 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_type_print(char c, va_list vargs, int *total, int *i)
{
	if (c == 'c')
		ft_printchar(va_arg(vargs, int), total);
	else if (c == 's')
		ft_printstring(va_arg(vargs, char *), total);
	else if (c == 'i' || c == 'd')
		ft_printinteger(va_arg(vargs, int), total);
	else if (c == 'p')
		ft_printpointer(va_arg(vargs, unsigned long long), total);
	else if (c == 'x' || c == 'X')
		ft_printhexa(va_arg(vargs, unsigned int), c, total);
	else if (c == 'u')
		ft_printunsigned(va_arg(vargs, unsigned int), total);
	else if (c == '%')
		ft_printchar('%', total);
	else
		(*i)--;
}

int	ft_printf(const char *string, ...)
{
	int		total;
	int		i;
	va_list	vargs;

	total = 0;
	i = 0;
	va_start(vargs, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			ft_type_print(string[++i], vargs, &total, &i);
			if (total == -1)
				return (-1);
			i++;
		}
		else
		{
			ft_printchar((char)string[i++], &total);
			if (total == -1)
				return (-1);
		}
	}
	va_end(vargs);
	return (total);
}
