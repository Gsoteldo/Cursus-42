/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:15:16 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:19:20 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Imprime un número entero en formato hexadecimal.
 * Si el número es menor o igual a 9, imprime el número como un dígito 
 * decimal.
 * Si el número es mayor que 9, imprime el número como un dígito hexadecimal.
 *
 * @param n: El número entero a imprimir en formato hexadecimal.
 * @param total: Un puntero a un entero que se actualizará con el número 
 * de caracteres escritos.
 */
static void	ft_printer(int n, int *total)
{
	if (n <= 9)
		ft_printchar(n + '0', total);
	else
		ft_printchar(n - 10 + 'a', total);
}

/**
 * Imprime un número entero en formato hexadecimal.
 * Si el número es mayor o igual a 16, llama a sí misma recursivamente 
 * con el número dividido por 16 y luego con el resto de la división por 16.
 * Si el número es menor o igual a 9, llama a ft_printer para imprimir 
 * el número.
 *
 * @param n: El número entero a imprimir en formato hexadecimal.
 * @param total: Un puntero a un entero que se actualizará con el
 * número de caracteres escritos.
 */

static void	ft_printhexapointer(unsigned long long n, int *total)
{
	int	aux;

	if (n >= 16)
	{
		ft_printhexapointer(n / 16, total);
		aux = *total;
		if (aux == -1)
		{
			*total = -1;
			return ;
		}
		ft_printhexapointer(n % 16, total);
		aux = *total;
		if (aux == -1)
		{
			*total = -1;
			return ;
		}
	}
	else
		ft_printer(n, total);
}

/**
 * Imprime un puntero en formato hexadecimal.
 * Primero imprime "0x", luego llama a ft_printhexapointer para 
 * imprimir el puntero.
 *
 * @param pointer: El puntero a imprimir.
 * @param total: Un puntero a un entero que se actualizará con 
 * el número de caracteres escritos.
 */

void	ft_printpointer(unsigned long long pointer, int *total)
{
	int	aux;

	ft_printstring("0x", total);
	aux = *total;
	if (aux == -1)
	{
		*total = -1;
		return ;
	}
	ft_printhexapointer(pointer, total);
	aux = *total;
	if (aux == -1)
	{
		*total = -1;
		return ;
	}
}
