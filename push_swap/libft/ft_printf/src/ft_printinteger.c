/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printinteger.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:13:51 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:18:51 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Imprime el número entero más pequeño posible en formato decimal.
 * Primero imprime un guión "-", luego imprime el número 2147483648.
 *
 * @param total: Un puntero a un entero que se actualizará con el 
 * número de caracteres escritos.
 * @return: El número de caracteres escritos.
 */

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

/**
 * Imprime un número entero negativo en formato decimal.
 * Primero imprime un guión "-", luego imprime el número absoluto 
 * del número negativo.
 *
 * @param n: El número entero negativo a imprimir.
 * @param total: Un puntero a un entero que se actualizará con 
 * el número de caracteres escritos.
 * @return: El número de caracteres escritos.
 */

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

/**
 * Imprime un número entero positivo en formato decimal.
 * Primero imprime el número dividido por 10, luego imprime 
 * el último dígito del número.
 *
 * @param n: El número entero positivo a imprimir.
 * @param total: Un puntero a un entero que se actualizará 
 * con el número de caracteres escritos.
 * @return: El número de caracteres escritos.
 */

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

/**
 * Imprime un número entero en formato decimal.
 * Dependiendo del valor del número, llama a min_negative, 
 * negative_numbers o other_cases.
 *
 * @param n: El número entero a imprimir.
 * @param total: Un puntero a un entero que se actualizará 
 * con el número de caracteres escritos.
 */

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
