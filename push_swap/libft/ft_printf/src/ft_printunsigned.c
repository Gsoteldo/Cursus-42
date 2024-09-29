/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:33 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:23:53 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Imprime un número entero sin signo en la salida estándar.
 * Si el número es menor o igual a 9, imprime el número como un dígito 
 * decimal.
 * Si el número es mayor que 9, llama a sí misma recursivamente con el 
 * número dividido por 10 y luego imprime el último dígito del número.
 *
 * @param n: El número entero sin signo a imprimir.
 * @param total: Un puntero a un entero que se actualizará con el 
 * número de caracteres escritos.
 */

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
