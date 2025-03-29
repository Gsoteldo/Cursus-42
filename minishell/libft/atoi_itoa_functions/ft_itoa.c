/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:34:30 by pmendez-          #+#    #+#             */
/*   Updated: 2024/09/07 14:51:35 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Calcula el número de dígitos necesarios para representar un número entero.
 * Si el número es negativo, cuenta el signo negativo como un dígito adicional.
 *
 * @param n: Número entero cuyo número de dígitos se desea calcular.
 * @return El número total de dígitos necesarios para representar `n`,
 *         incluyendo el signo negativo si es aplicable.
 */
static int	ft_numcif(int n)
{
	long int	nb;
	int			numcif;

	nb = n;
	numcif = 0;
	if (nb < 0)
	{
		nb = -nb;
		numcif++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		numcif++;
	}
	return (numcif);
}

/**
 * Reserva memoria para una cadena de caracteres que representará un número
 * entero. Si el número es 0, reserva espacio para dos caracteres (para el '0'
 * y otro para el terminador nulo). Si el número no es 0, reserva suficiente
 * espacio para todos los dígitos y un terminador nulo.
 *
 * @param string: Puntero a la cadena de caracteres que se va a reservar (NULL).
 * @param numcif: Número total de dígitos necesarios para representar el número.
 * @param nb: Número entero que se va a convertir en cadena.
 * @return Un puntero a la memoria reservada, o NULL si la reserva falla.
 */
static char	*ft_reserve(char *string, int numcif, long int nb)
{
	if (nb == 0)
	{
		string = ft_calloc(2, sizeof(char));
		if (string == NULL)
			return (0);
	}
	else
	{
		string = ft_calloc(numcif + 1, sizeof(char));
		if (string == NULL)
			return (0);
	}
	return (string);
}

/**
 * Convierte un número entero a una cadena de caracteres.
 * Maneja números negativos y el caso especial del número 0. Reserva memoria
 * para la cadena, convierte el número a una representación textual, y
 * devuelve la cadena resultante.
 *
 * @param n: Número entero que se convertirá a una cadena.
 * @return Un puntero a la cadena de caracteres que representa el número,
 *         o NULL si la reserva de memoria falla.
 */
char	*ft_itoa(int n)
{
	char		*string;
	int			numcif;
	long int	nb;

	nb = n;
	string = NULL;
	numcif = ft_numcif(nb);
	string = ft_reserve(string, numcif, nb);
	if (string == NULL)
		return (0);
	string[numcif--] = 0;
	if (nb == 0)
		string[0] = '0';
	if (nb < 0)
	{
		string[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		string[numcif--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (string);
}
