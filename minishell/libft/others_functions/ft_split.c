/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:19:11 by pmendez-          #+#    #+#             */
/*   Updated: 2024/09/07 14:44:41 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Cuenta el número de subcadenas en una cadena delimitadas por un carácter.
 * Itera a través de la cadena `str`, contando las subcadenas que están
 * separadas por el carácter delimitador `c`.
 *
 * @param str: Cadena en la que se cuentan las subcadenas.
 * @param c: Carácter delimitador que separa las subcadenas.
 * @return El número de subcadenas en la cadena `str`.
 */
static int	count_character(char *str, char c)
{
	int	cont;
	int	numstr;

	cont = 0;
	numstr = 0;
	while (str[cont] != '\0')
	{
		if (str[cont] != c)
		{
			numstr++;
			while (str[cont] != c && str[cont] != '\0')
				cont++;
		}
		else
			cont++;
	}
	return (numstr);
}

/**
 * Reserva memoria y copia una subcadena desde una posición específica.
 * Calcula la longitud de la subcadena desde la posición indicada por `pos`
 * hasta el próximo delimitador `c` o el final de la cadena,
 * reserva memoria para la subcadena, la copia, y actualiza la posición.
 *
 * @param str: Cadena original de la que se extrae la subcadena.
 * @param c: Carácter delimitador que indica el final de la subcadena.
 * @param pos: Puntero a la posición actual en la cadena,
 * se actualizará al final de la subcadena copiada.
 * @return Un puntero a la nueva subcadena copiada. Retorna NULL
 * si la reserva de memoria falla.
 */
static char	*reserve_and_copy_str(char *str, char c, int *pos)
{
	char	*result;
	int		str_length;
	int		i;

	i = *pos;
	str_length = 0;
	result = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		str_length++;
		i++;
	}
	result = (char *)ft_calloc((str_length + 1), sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, str + *pos, str_length + 1);
	*pos += str_length;
	return (result);
}

/**
 * Divide una cadena en subcadenas utilizando un delimitador especificado.
 * Crea un array de subcadenas separadas por el carácter delimitador `c`,
 * asignando memoria para cada subcadena. Devuelve un array de cadenas,
 * donde cada cadena es una subcadena de la cadena original `s`.
 *
 * @param s: Cadena de entrada que se desea dividir.
 * @param c: Carácter delimitador utilizado para separar la cadena.
 * @return Un array de cadenas, donde cada cadena es una subcadena de `s`
 * separada por `c`. El último elemento del array es un puntero NULL.
 */
char	**ft_split(char *s, char c)
{
	char	**result;
	int		numstr;
	int		j;
	int		pos;

	if (s == NULL)
		return (NULL);
	j = 0;
	pos = 0;
	numstr = count_character((char *)s, c);
	result = (char **)ft_calloc((numstr + 1), sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (j < numstr && result != NULL)
	{
		while (s[pos] == c)
			pos++;
		result[j] = reserve_and_copy_str((char *)s, c, &pos);
		if (result[j] == NULL)
			return (NULL);
		j++;
	}
	return (result);
}
