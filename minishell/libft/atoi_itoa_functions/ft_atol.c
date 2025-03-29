/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:03:23 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/09/07 14:52:08 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Convierte una cadena de caracteres en un número entero largo.
 * Analiza la cadena `str` para extraer un número entero, considerando espacios
 * en blanco, y opcionalmente un signo (+ o -) al principio. La conversión se
 * realiza hasta encontrar un carácter no numérico.
 *
 * @param str: Cadena de caracteres que representa el número a convertir.
 * @return El número entero largo resultante de la conversión. Si la 
 * 			cadena no contiene un número válido, devuelve 0.
 */
long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
