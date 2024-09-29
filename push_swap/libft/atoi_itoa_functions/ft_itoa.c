/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:55:54 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:08:50 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/** digit_counter
 * Cuenta el número de dígitos en el número entero proporcionado.
 * Devuelve 1 para el número 0, 11 para el número -2147483648 y el número de 
 * dígitos para otros números.
 *
 * @param n: El número entero para contar los dígitos.
 * @return El número de dígitos en el número entero.
 */

static int	digit_counter(int n)
{
	int	i;
	int	copy;

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
	copy = n;
	while (copy > 0)
	{
		copy = copy / 10;
		i++;
	}
	return (i);
}

/** exp_counter
 * Calcula la potencia de 10 equivalente al número de dígitos en el 
 * número entero proporcionado.
 * Devuelve 1 para el número 0 y 1000000000 para el número -2147483648.
 * Para otros números, calcula la potencia de 10 que es igual al 
 * número de dígitos.
 *
 * @param n: El número entero para calcular la potencia de 10.
 * @return La potencia de 10 equivalente al número de dígitos 
 * en el número entero.
 */

static int	exp_counter(int n)
{
	int	exp;
	int	digits;

	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (1000000000);
	digits = digit_counter(n);
	if (n < 0)
		digits--;
	exp = 1;
	while (--digits)
		exp = exp * 10;
	return (exp);
}

/** ft_itoa
 * Convierte un número entero a una cadena de caracteres.
 * Primero calcula la cantidad de dígitos y la potencia de 
 * 10 correspondiente utilizando las funciones anteriores.
 * Luego, divide el número por la potencia de 10, obtiene el 
 * resto, y convierte el cociente y el resto a caracteres.
 * Finalmente, añade los caracteres a la cadena resultante.
 *
 * @param n: El número entero a convertir a una cadena de caracteres.
 * @return: La cadena de caracteres correspondiente al número entero.
 */

char	*ft_itoa(int n)
{
	char		*str;
	int			exp;
	int			i;
	long int	copy;

	copy = (long int)n;
	exp = exp_counter(n);
	i = 0;
	str = malloc(digit_counter(n) + 1);
	if (!(str))
		return (NULL);
	if (n < 0)
	{
		str[i++] = '-';
		copy = -copy;
	}
	while (exp > 0)
	{
		str[i++] = (copy / exp) + 48;
		copy = copy % exp;
		exp = exp / 10;
	}
	str[i] = '\0';
	return (str);
}
